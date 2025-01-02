#include "Renderer/Renderer.h"
#include "Intervalometer/IntMeter.h"

int main() {
  Window* w = new Window();
  w->setPosition(0, 0);
  w->setResolution(800,600);
  w->setTitle("bogus");

  Renderer* r = new Renderer();
   r->createWindow(w);
  IntMeter i;
  i.addExecution([w](){w->printFPS();}, 10e5);
  i.addTimeout([w](){printf("bingus");}, 20e5);

  while(r->running()){
  }
  i.clearTimeouts();


  return 0;
}

