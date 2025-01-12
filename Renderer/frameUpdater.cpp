#include "Window.h"
#include "Renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <mutex>


void Renderer::frameUpdater(Window* w){
  if(!active){
    return;
  }
    
  if(!w->isReady()){
    printf("Window not initialized\n");
    return;
  }

  std::cout <<"Spawning window "<< w->title << '\n';
  std::cout <<"At x: "<< w->position->x();
  std::cout <<" y: " <<w->position->y()<<'\n';
  std::cout <<"Resolution x: " << w->resolution->x();
  std::cout << " y: " <<w->resolution->y()<<'\n';
    
  Uint32 flags = 0;
    
  if(w->borderless){
    flags |= SDL_WINDOW_BORDERLESS;
  }
  if(w->shown){
    flags |= SDL_WINDOW_SHOWN;
  }
    
  flags |= w->additionalFlags;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL2 initialization failed: " << SDL_GetError() << std::endl;
    return;
  }

  SDL_Window* window = SDL_CreateWindow(
    w->title.c_str(),
    w->position->x(), w->position->y(),
    w->resolution->x(), w->resolution->y(),
    flags
  );
  if(!window){
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return;
  }
    
  int width = w->resolution->x();
  int height = w->resolution->y();
 
    

  SDL_Renderer* pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(!pRenderer){
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

  while(running){
      t0 = std::chrono::high_resolution_clock::now();
      std::this_thread::sleep_for(std::chrono::milliseconds(w->timeout));
      if(!active){
        return;
      }

      while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT ||  event.type == SDL_WINDOWEVENT_CLOSE){
          w->closing = true;
          goto end;
        }
      }
    std::lock_guard<std::mutex> lock(mtx);
      SDL_UpdateTexture(texture, NULL, w->frameBuffer[w->activeBuff], width * 4 );
      //SDL_RenderClear(pRenderer);
      SDL_RenderCopy(pRenderer, texture, NULL, NULL);

      SDL_RenderPresent(pRenderer);
      t1 =  std::chrono::high_resolution_clock::now();
      w->fps = (int)10e6/std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
  }
  end:
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  cv.notify_all();

  return;
}

