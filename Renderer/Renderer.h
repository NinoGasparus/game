#ifndef RENDERER_H
#define RENDERER_H
#include "../DataStruct/Vector/Vector.h"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

class Window;

class Renderer{
  private:

    static std::condition_variable cv;
    static std::mutex mtx;

    static std::atomic<int> wkCount;
    static std::atomic<bool> active;
    static std::vector<std::thread> workers;
    static void frameUpdater(Window* w);
    
    static  void threadTerminator();
  public:
    unsigned char * frameBuffer;

    Renderer();
    bool running();     
    void createWindow(Window* w);
};


#endif // !RENDERER_H


