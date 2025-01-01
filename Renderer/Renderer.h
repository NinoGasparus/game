#ifndef RENDERER_H
#define RENDERER_H
#include "../DataStruct/Vector/Vector.h"


class Renderer{
  private:
  public:
    unsigned char * frameBuffer;
    Vec2D<int> windowSize;
    bool active = false; 
    
    Renderer();
    
    void createWindow(Vec2D<int> resolution);

};


#endif // !RENDERER_H


