#include "Drawable.h"
#include "../Renderer/Window.h"
#include <cstdint>


template <typename T>
void Point<T>::Draw(Window* w){
  w->frameBuffer[(int)this->y()*(int)w->resolution->x()+(int)this->x()] =(uint32_t)*this->col;
}

template class Point<int>;
template class Point<float>;
template class Point<double>;
template class Point<char>;
template class Point<uint8_t>;
template class Point<uint16_t>;
template class Point<uint32_t>;
template class Point<uint64_t>;
template class Point<int8_t>;
template class Point<int16_t>;
template class Point<int64_t>;
