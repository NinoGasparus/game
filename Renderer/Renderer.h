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
    
    int targetFPS = 0;
    int maxFPS    = 0;
    int minFPS    = 0;
    
    void frameUpdater();
    
    Window drawingTargetWindow();
  public:
    unsigned char * frameBuffer;
    Vec2D<int> windowSize;  
     
    Renderer();
     
    void createWindow(Window w);
};

class Window{
private:
    
public:
    std::string title = "";
    Vec2D<int> position;
    Vec2D<int> resolution; 
    bool shown = true;
    bool borderless = false;
    Uint32 additionalFlags;
    
    SDL_Window* win;
    
    Window();
    Window(const std::string& t); 
    Window(const std::string& t, const Vec2D<int>& res); 
    Window(const std::string& t, const Vec2D<int>& res, bool s); 
    Window(const std::string& t, const Vec2D<int>& res, Uint32 flags); 
    Window(const std::string& t, bool s, bool b); 
    Window(const std::string& t, bool s, Uint32 flags); 
    Window(const Vec2D<int>& res, bool s, bool b); 
    Window(const Vec2D<int>& res, bool s, Uint32 flags); 
    Window(const std::string& t, const Vec2D<int>& pos, const Vec2D<int>& res, bool s, bool b, Uint32 flags);
    
    void setTitle(char* title);
    void setTitle(std::string title);

    void setPosition(int x, int y);
    void setPosition(Vec2D<int> position);
  
    void setResolution(int x, int y);
    void setResolution(Vec2D<int> resolution);
    
    void addFlags(Uint32 flags);
  
    bool isReady();
    void spawn();
};


#endif // !RENDERER_H


