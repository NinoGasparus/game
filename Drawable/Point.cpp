#include "Drawable.h"
#include "../Renderer/Renderer.h"



template <typename T>
void Point<T>::Draw(Renderer* r) {
r->frameBuffer[this->pos.y() * r->windowSize.x() + this->pos.x()+0] = this->col->r;
r->frameBuffer[this->pos.y() * r->windowSize.x() + this->pos.x()+1] = this->col->g;
r->frameBuffer[this->pos.y() * r->windowSize.x() + this->pos.x()+2] = this->col->b;
}

