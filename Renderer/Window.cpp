#include "Renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <string>
bool Window::isReady(){
  if(title == ""){
    return false;
    printf("\nWindow title not set\n");
  }

  try{
    if(position.x() == 0 && position.y() == 0){
      if(position.checksum == 2){//should match dim of the vector if doesnt well it might not exist
          goto ok;
      }else{
          return false;
      }
    }

    if(resolution.x() ==0 && resolution.y() ==  0){
      if(resolution.checksum == 2){
        goto ok;
      }else{
        return false;
      }
    }
    
  }catch(int ex){
    return false;
  };
  ok:
  if(shown != true || shown != false){
    return false;
  } 

  if(borderless != true || borderless != false){
    return false;
  }

  
  return true;
}


void Window::spawn(){
  if(!isReady()){
    printf("Window not initialized, missing required parameters");
    return;
  }


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL2 initialization failed: " << SDL_GetError() << std::endl;
        return;
    }
	  Uint32 flags;
    if(shown){
      flags  = SDL_WINDOW_SHOWN;
    }

    if(borderless){
      flags |= SDL_WINDOW_BORDERLESS;     
    }
    flags |=additionalFlags;

    SDL_Window* window = SDL_CreateWindow(
        title.c_str(),
        position.x(), position.y(),resolution.x(), resolution.y(),
        flags
    );
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    
    this->win = window;

}

void Window::setTitle(char* title){
  this->title = title;
}

void Window::setTitle(std::string title){
  this->title = title;
}

void Window::setPosition(int x, int y){
  if(this->position.checksum != 2){
    this->position = Vec2D<int>();
    this->position.x() = x;
    this->position.y() = y;
  }else{
    this->position.x() = x;
    this->position.y() = y;

  }
}

void Window::setPosition(Vec2D<int> position){
  if(this->position.checksum != 2){
    this->position = position;
  }else{
    this->position.x() = position.x();
    this->position.y() = position.y();

  }
}


void Window::setResolution(int x, int y){
  if(this->resolution.checksum != 2){
    this->resolution= Vec2D<int>();
    this->resolution.x() = x;
    this->resolution.y() = y;
  }else{
    this->resolution.x() = x;
    this->resolution.y() = y;

  }
}

void Window::setResolution(Vec2D<int>resolution){
  if(this->resolution.checksum != 2){
    this->resolution= position;
  }else{
    this->resolution.x() = resolution.x();
    this->resolution.y() = resolution.y();


  }
}


void Window::addFlags(Uint32 flags){
  additionalFlags |= flags;
}

Window::Window() {
    title = "Untitled";
    position = Vec2D<int>();
    resolution = Vec2D<int>();
    shown = true;
    borderless = false;
    additionalFlags = 0;
}

Window::Window(const std::string& t) {
    title = t;
    position = Vec2D<int>();
    resolution = Vec2D<int>();
    shown = true;
    borderless = false;
    additionalFlags = 0;
}

Window::Window(const std::string& t, const Vec2D<int>& res) {
    title = t;
    position = Vec2D<int>();
    resolution = res;
    shown = true;
    borderless = false;
    additionalFlags = 0;
}
Window::Window(const std::string& t, const Vec2D<int>& res, bool s) {
    title = t;
    position = Vec2D<int>();
    resolution = res;
    shown = s;
    borderless = false;
    additionalFlags = 0;
}

Window::Window(const std::string& t, const Vec2D<int>& res, Uint32 flags) {
    title = t;
    position = Vec2D<int>();
    resolution = res;
    shown = true;
    borderless = false;
    additionalFlags = flags;
}

Window::Window(const std::string& t, bool s, bool b) {
    title = t;
    position = Vec2D<int>();
    resolution = Vec2D<int>();
    shown = s;
    borderless = b;
    additionalFlags = 0;
}

Window::Window(const std::string& t, bool s, Uint32 flags) {
    title = t;
    position = Vec2D<int>();
    resolution = Vec2D<int>();
    shown = s;
    borderless = false;
    additionalFlags = flags;
}

Window::Window(const Vec2D<int>& res, bool s, bool b) {
    title = "Untitled";
    position = Vec2D<int>();
    resolution = res;
    shown = s;
    borderless = b;
    additionalFlags = 0;
}

Window::Window(const Vec2D<int>& res, bool s, Uint32 flags) {
    title = "Untitled";
    position = Vec2D<int>();
    resolution = res;
    shown = s;
    borderless = false;
    additionalFlags = flags;
}

Window::Window(const std::string& t, const Vec2D<int>& pos, const Vec2D<int>& res, bool s, bool b, Uint32 flags) {
    title = t;
    position = pos;
    resolution = res;
    shown = s;
    borderless = b;
    additionalFlags = flags;
}

