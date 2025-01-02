#ifndef INTMETER_H
#define INTMETER_H

#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class IntMeter{
  private:
    struct Task {
      std::function<void()> func;
      int64_t intervalUs;
      bool repeat;
      std::chrono::steady_clock::time_point nextExecution;
    };

    std::vector<Task> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool running;
    std::thread worker;

    void workerThread();
  public:
    IntMeter();

    void addTimeout(const std::function<void()>& func, int64_t timeoutUs);
    void addExecution(const std::function<void()>& func, int64_t intervalUs);
    void clearTimeouts();
    ~IntMeter();
};


#endif // !INTMETER
