#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <condition_variable>
#include <cstdio>
#include <mutex>
#include <thread>
#include <vector>

#include "Renderer.h"
#include "Window.h"


std::atomic<int>Renderer::wkCount = 0;
std::atomic<bool>Renderer::active=true;
std::vector<std::thread> Renderer::workers;
std::condition_variable Renderer::cv;
std::mutex  Renderer::mtx;

void Renderer::createWindow(Window* w){
  w->closing = false;
  active = true;
  Renderer();
  workers.emplace_back(std::thread(frameUpdater, w));
  wkCount++;
}

void Renderer::threadTerminator(){
  while(true){
    std::unique_lock<std::mutex> lock(mtx);
    
    cv.wait(lock, []{ return Window::closing;});
    for (size_t i = 0; i < workers.size(); ) {
      workers[i].join();  
      wkCount--;        
      workers.erase(workers.begin() + i);
    }
    lock.unlock();
    break;
  }
  active = false;
  return;
}

Renderer::Renderer(){
  active = true;
  std::thread master(&Renderer::threadTerminator);
  master.detach();
}
bool Renderer::running() {
  return active;
}


