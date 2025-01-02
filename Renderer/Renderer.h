#ifndef RENDERER_H
#define RENDERER_H
#include "../DataStruct/Vector/Vector.h"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <cstdint>
#include <string>

class Window;

class Renderer{
  private:
    bool active = false;
    void frameUpdater();
  public:
    unsigned char * frameBuffer;

    Renderer();
     
    void createWindow(Window* w);
};

class Window{
private:
    int targetFPS = 0;
    int maxFPS    = 0;
    int minFPS    = 0;
public:
    std::string title = "";
    Vec2D<int>* position = new Vec2D<int>();
    Vec2D<int>* resolution = new Vec2D<int>(); 
    bool shown = true;
    bool borderless = false;
    Uint32 additionalFlags;
    int fps = 0;    
    
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
};


#endif // !RENDERER_H


