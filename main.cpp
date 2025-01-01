#include <SDL2/SDL.h>
#include <iostream>
#include <chrono>
#include "DataStruct/Vector/Vector.h"

int main() {
	//shit might happen
  Vec2D* v= new Vec2D();
  v->x() = 3;
  v->y() = 4;
  v->normalize();
  v->print();
  printf("%f", v->mag());
  
  
	/*
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL2 initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }
	
    SDL_Window* window = SDL_CreateWindow(
        "bogus",
        100, 100, 800, 100,
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS
    );

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!pRenderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create the framebuffer (800x600, 32-bit color)
    int width = 800;
    int height = 100;
    uint32_t* framebuffer = new uint32_t[width * height];  // 32-bit color (RGBA)

    // Fill the framebuffer with a solid color (e.g., red)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            framebuffer[y * width + x] = 0xFF0000FF; // Red color (RGBA)
        }
    }

    // Create an SDL texture to hold the framebuffer data
    SDL_Texture* texture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    // Main loop to display the framebuffer
    bool running = true;
    SDL_Event event;
    auto t0 = std::chrono::high_resolution_clock::now();
    auto t1 = std::chrono::high_resolution_clock::now();

    while (running) {
        // Handle events
         t0 = std::chrono::high_resolution_clock::now();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Update the texture with the framebuffer data
        SDL_UpdateTexture(texture, NULL, framebuffer, width * sizeof(uint32_t));

        // Clear the renderer
        SDL_RenderClear(pRenderer);

        // Copy the texture to the renderer (to the window)
        SDL_RenderCopy(pRenderer, texture, NULL, NULL);

        // Present the renderer to the screen
        SDL_RenderPresent(pRenderer);
      t1 =  std::chrono::high_resolution_clock::now();
      std::cout << 10e6/std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count() << " FPS\n";
    }

    // Cleanup
    delete[] framebuffer; // Free the framebuffer memory
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
*/
    return 0;
}

