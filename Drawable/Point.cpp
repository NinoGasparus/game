#include "Drawable.h"
#include "../Renderer/Renderer.h"


void Point::Draw(Renderer r) {
  frameBuffer[this->pos->y() * r.windowSize.x() + this->pos.x()] = this->col->r;
  frameBuffer[this->pos->y() * r.windowSize.x() + this->pos.x()+1] = this->col->g;
  frameBuffer[this->pos->y() * r.windowSize.x() + this->pos.x()+2] = this->col->b;

}
