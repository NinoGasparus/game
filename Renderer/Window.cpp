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
    if(position->x() == 0 && position->y() == 0){
      if(position->checksum == 2){//should match dim of the vector if doesnt well it might not exist
          goto ok;
      }else{
          printf("\nPosition not set\n");
          return false;
      }
    }

    if(resolution->x() ==0 && resolution->y() ==  0){
      if(resolution->checksum == 2){
        goto ok;
      }else{
        printf("\nResolution not set\n");
        return false;
      }
    }
    
  }catch(int ex){
    printf("\nTryCatch failed\n");
    return false;
  };
  ok:
  if(shown != true && shown != false){
    printf("\nShown in invalid state\n");
    return false;
  } 

  if(borderless != true && borderless != false){
    printf("\nBorderless in invalid state\n");
    return false;
  }

  
  return true;
}



void Window::setTitle(char* title){
  this->title = std::string(title);
}

void Window::setTitle(std::string title){
  this->title = title;
}

void Window::setPosition(int x, int y){
  if(this->position->checksum != 2){
    this->position = new Vec2D<int>();
    this->position->x() = x;
    this->position->y() = y;
  }else{
    this->position->x() = x;
    this->position->y() = y;

  }
}

void Window::setPosition(Vec2D<int>position){
  if(this->position->checksum != 2){
    this->position = &position;
  }else{
    this->position->x() = position.x();
    this->position->y() = position.y();

  }
}


void Window::setResolution(int x, int y){
  if(this->resolution->checksum != 2){
    this->resolution=new Vec2D<int>();
    this->resolution->x() = x;
    this->resolution->y() = y;
  }else{
    this->resolution->x() = x;
    this->resolution->y() = y;

  }
}

void Window::setResolution(Vec2D<int>resolution){
  if(this->resolution->checksum != 2){
    this->resolution= position;
  }else{
    this->resolution->x() = resolution.x();
    this->resolution->y() = resolution.y();


  }
}


void Window::addFlags(Uint32 flags){
  additionalFlags |= flags;
}

Window::Window() {
    title = "Untitled";
    shown = true;
    borderless = false;
    additionalFlags = 0;
}

Window::Window(const std::string& t) {
    title = t;
    shown = true;
    borderless = false;
    additionalFlags = 0;
}

Window::Window(const std::string& t, Vec2D<int>& res) {
    title = t;
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = true;
    borderless = false;
    additionalFlags = 0;
}
Window::Window(const std::string& t, Vec2D<int>& res, bool s) {
    title = t;
    shown = s;
    resolution->x() = res.x();
    resolution->y() = res.y();
    borderless = false;
    additionalFlags = 0;
}

Window::Window(const std::string& t, Vec2D<int>& res, Uint32 flags) {
    title = t;
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = true;
    borderless = false;
    additionalFlags = flags;
}

Window::Window(const std::string& t, bool s, bool b) {
    title = t;
    shown = s;
    borderless = b;
    additionalFlags = 0;
}

Window::Window(const std::string& t, bool s, Uint32 flags) {
    title = t;
    shown = s;
    borderless = false;
    additionalFlags = flags;
}

Window::Window(Vec2D<int>& res, bool s, bool b) {
    title = "Untitled";
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = s;
    borderless = b;
    additionalFlags = 0;
}

Window::Window(Vec2D<int>& res, bool s, Uint32 flags) {
    title = "Untitled";
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = s;
    borderless = false;
    additionalFlags = flags;
}

Window::Window(const std::string& t, Vec2D<int>& pos, Vec2D<int>& res, bool s, bool b, Uint32 flags) {
    title = t;
    position->x() = pos.x();
    position->y() = pos.y();
    resolution->x() = res.x();
    resolution->y() = res.y();
    shown = s;
    borderless = b;
    additionalFlags = flags;
}

