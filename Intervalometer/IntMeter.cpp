#include "IntMeter.h"
#include <algorithm>
#include <functional>
#include <mutex>



IntMeter::IntMeter(){
    running = true;
    worker = std::thread(&IntMeter::workerThread, this);
}

IntMeter::~IntMeter() {
    std::lock_guard<std::mutex> lock(mtx);
    running = false;
    
    cv.notify_all();
    if (worker.joinable()) {
        worker.join();
    }
}

void IntMeter::addTimeout(const std::function<void()>& func, int64_t timeoutUs) {
    std::lock_guard<std::mutex> lock(mtx);
    tasks.push_back({func, timeoutUs, false, std::chrono::steady_clock::now() + std::chrono::microseconds(timeoutUs)});
    cv.notify_all();
}

void IntMeter::addExecution(const std::function<void()>& func, int64_t intervalUs) {
    std::lock_guard<std::mutex> lock(mtx);
    tasks.push_back({func, intervalUs, true, std::chrono::steady_clock::now() + std::chrono::microseconds(intervalUs)});
    cv.notify_all();
}

void IntMeter::workerThread() {
    while (running) {
        std::unique_lock<std::mutex> lock(mtx);

        if (tasks.empty()) {
            cv.wait(lock); 
        } else {
            auto now = std::chrono::steady_clock::now();
            auto it = std::min_element(tasks.begin(), tasks.end(),
                                       [now](const Task& a, const Task& b) {
                                           return a.nextExecution < b.nextExecution;
                                       });

            if (it->nextExecution > now) {
                cv.wait_until(lock, it->nextExecution);
            } else {
                auto task = *it;
                if (!task.repeat) {
                    tasks.erase(it);
                } else {
                    it->nextExecution = now + std::chrono::microseconds(it->intervalUs);
                }

                lock.unlock();
                task.func();
                lock.lock();
            }
        }
    }
}

void IntMeter::clearTimeouts(){
  running = false;
  cv.notify_all();
  while (!worker.joinable()){
    
  }
  worker.join();
}
