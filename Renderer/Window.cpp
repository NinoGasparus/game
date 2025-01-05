#include "Window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <cstdint>
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
    
  }catch(...){
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
    delete frameBuffer;
  if(this->resolution->checksum != 2){
    this->resolution=new Vec2D<int>();
    this->resolution->x() = x;
    this->resolution->y() = y;
  }else{
    this->resolution->x() = x;
    this->resolution->y() = y;

  }

 this->frameBuffer = new uint32_t[this->resolution->x() * this->resolution->y()];

}

void Window::setResolution(Vec2D<int>resolution){
    delete frameBuffer;
  if(this->resolution->checksum != 2){
    this->resolution= position;
  }else{
    this->resolution->x() = resolution.x();
    this->resolution->y() = resolution.y();


  }
   this->frameBuffer = new uint32_t[this->resolution->x() * this->resolution->y()];

}


void Window::addFlags(Uint32 flags){
  additionalFlags |= flags;
}


void Window::getTimeout(){
  if(targetFPS== -1){
    this->timeout = 0;
    return;
  } 
  this->timeout =(int) 10000/(this->targetFPS);
}

void Window::init(){
  this->frameBuffer = new uint32_t[this->resolution->x() * this->resolution->y()];
  this->clock = new IntMeter();
  this->clock->addExecution([this](){this->getTimeout();}, 50000);
}

