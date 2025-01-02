#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "Renderer.h"

Renderer::Renderer(){
  return;
}
void Renderer::createWindow(Window w){
    if(!w.isReady()){
      printf("Window not initialized\n");
      return;

    }
    int width = 800;
    int height = 100;
    uint32_t* framebuffer = new uint32_t[width * height];  

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            framebuffer[y * width + x] = 0xFF0000FF; 
        }
    }

  
    

    SDL_Renderer* pRenderer = SDL_CreateRenderer(w.win, -1, SDL_RENDERER_ACCELERATED);
    if (!pRenderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(w.win);
        SDL_Quit();
        return;
    }


    SDL_Texture* texture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    bool running = true;
    SDL_Event event;
  //  auto t0 = std::chrono::high_resolution_clock::now();
  // auto t1 = std::chrono::high_resolution_clock::now();

    while (running) {
   //      t0 = std::chrono::high_resolution_clock::now();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_UpdateTexture(texture, NULL, framebuffer, width * sizeof(uint32_t));

        SDL_RenderClear(pRenderer);

        SDL_RenderCopy(pRenderer, texture, NULL, NULL);

        SDL_RenderPresent(pRenderer);
//      t1 =  std::chrono::high_resolution_clock::now();
 //     std::cout << 10e6/std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count() << " FPS\n";
    }

    delete[] framebuffer; 
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(w.win);
    SDL_Quit();

}



void Renderer::frameUpdater(){
  if(!this->active){
    return;
  }
}
