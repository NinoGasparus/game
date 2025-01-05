#ifndef WINDOW_H
#define WINDOW_H

#include "../DataStruct/Vector/Vector.h"
#include "../Intervalometer/IntMeter.h"
#include <SDL2/SDL_stdinc.h>
#include <cstdint>
#include <string>


class Window{
  private:
    int targetFPS = 60;
    int maxFPS    = 0;
    int minFPS    = 0;
    
  
    IntMeter* clock;
    void getTimeout();
  public:
    std::string title = "";
    Vec2D<int>* position = new Vec2D<int>();
    Vec2D<int>* resolution = new Vec2D<int>(); 
    bool shown = true;
    bool borderless = false;
    Uint32 additionalFlags;
    int fps = 0;    
    int  timeout =0;
    uint32_t* frameBuffer;   
    static bool closing;
    
    void  init();

    Window();
    Window(const std::string& t); 
    Window(const std::string& t, Vec2D<int>& res); 
    Window(const std::string& t, Vec2D<int>& res, bool s); 
    Window(const std::string& t, Vec2D<int>& res, Uint32 flags); 
    Window(const std::string& t, bool s, bool b); 
    Window(const std::string& t, bool s, Uint32 flags); 
    Window(Vec2D<int>& res, bool s, bool b); 
    Window(Vec2D<int>& res, bool s, Uint32 flags); 
    Window(const std::string& t, Vec2D<int>& pos, Vec2D<int>& res, bool s, bool b, Uint32 flags);
    
    void setTitle(char* title);
    void setTitle(std::string title);

    void setPosition(int x, int y);
    void setPosition(Vec2D<int> position);
  
    void setResolution(int x, int y);
    void setResolution(Vec2D<int> resolution);
    
    void addFlags(Uint32 flags);
  
    bool isReady();
    

    void setFPS(int  targetFps){
      this->targetFPS = targetFps;
    }
    void printFPS(){
      printf("FPS: %i\n", this->fps);
    }

    
    ~Window(){
    delete resolution;
    delete position;
    delete frameBuffer;
    }
};
#endif // !WINDOW_H
