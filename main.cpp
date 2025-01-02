#include "Renderer/Renderer.h"
int main() {
  Window* w = new Window();
  w->setPosition(0, 0);
  w->setResolution(400,800);
  w->setTitle("bogus");

  Renderer* r = new Renderer();
  r->createWindow(w);
  
  return 0;
}

