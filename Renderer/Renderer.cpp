#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "Renderer.h"
std::atomic<int>Renderer::wkCount = 0;
std::atomic<bool>Renderer::active=true;
std::vector<std::thread> Renderer::workers;
std::condition_variable Renderer::cv;
std::mutex  Renderer::mtx;

bool closing = false;  //set to true when windows should be closed than notify all waiters for cv

void Renderer::createWindow(Window* w){
  closing = false;
  active = true;
  Renderer();
  workers.emplace_back(std::thread(frameUpdater, w));
  wkCount++;
}

void Renderer::threadTerminator(){
  while(true){
    std::unique_lock<std::mutex> lock(mtx);
    
    cv.wait(lock, []{ return closing;});
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


 void Renderer::frameUpdater(Window* w){
  if(!active){
    return;
  }
  
    if(!w->isReady()){
      printf("Window not initialized\n");
      return;

    }

    std::cout << w->title << '\n';

    std::cout << w->position->x()<<'\n';
    std::cout << w->position->y()<<'\n';

    std::cout << w->resolution->x()<<'\n';
    std::cout << w->resolution->y()<<'\n';
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL2 initialization failed: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Window* window = SDL_CreateWindow(
        w->title.c_str(),
        w->position->x(), w->position->y(),
        w->resolution->x(), w->resolution->y(),
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    

    int width = w->resolution->x();
    int height = w->resolution->y();
    uint32_t* framebuffer = new uint32_t[width * height];  

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            framebuffer[y * width + x] = 0xFF0000FF; 
        }
    }

  
    

    SDL_Renderer* pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!pRenderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }


    SDL_Texture* texture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    bool running = true;
    SDL_Event event;
    auto t0 = std::chrono::high_resolution_clock::now();
    auto t1 = std::chrono::high_resolution_clock::now();

    while (running) {
      t0 = std::chrono::high_resolution_clock::now();
      std::this_thread::sleep_for(std::chrono::milliseconds(w->timeout));
      if(!active){
      return;
      }

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT ||  event.type == SDL_WINDOWEVENT_CLOSE) {
                closing = true;
                goto end;
            }
        }

        SDL_UpdateTexture(texture, NULL, framebuffer, width * sizeof(uint32_t));

        SDL_RenderClear(pRenderer);

        SDL_RenderCopy(pRenderer, texture, NULL, NULL);

        SDL_RenderPresent(pRenderer);
        t1 =  std::chrono::high_resolution_clock::now();
        w->fps = (int)10e6/std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
        
    }
    end:
    delete[] framebuffer; 
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cv.notify_all();

    return;
}

