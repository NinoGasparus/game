#include "Renderer/Renderer.h"
int main() {
  Renderer r;
  Window  w;
  w.setPosition(100,100);
  Vec2D<int> pos;
  pos.x() = 200;
  pos.y() = 400;
  w.setTitle("bogus");
  w.setResolution(pos);
  r.createWindow(w);
  
  return 0;
}

