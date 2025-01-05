#include "Drawable.h"
#include "../Renderer/Window.h"

template <typename T>
void Line<T>::Draw(Window* w) {
  int x0 = (int)(this->x1());
  int y0 = (int)(this->y1());
  int x1 = (int)(this->x2());
  int y1 = (int)(this->y2());

  int dx = std::abs(x1 - x0);
  int dy = std::abs(y1 - y0);
  int sx = (x0 < x1) ? 1 : -1; 
  int sy = (y0 < y1) ? 1 : -1; 
    
  int err = dx - dy;

    //flat line  edge case
  if(y1 == y0){
    for (int x = std::min(x1, x0); x <= std::max(x1, x0); x++) {
      if(x >= 0 && x < w->resolution->x() && y1 >= 0 && y1 < w->resolution->y()){
         w->frameBuffer[y1 * w->resolution->x() + x] = (uint32_t)(*this->col);
      }
    }
    return;
  }
  //tall line edge case
  if(x1 == x0) {
    for(int y = std::min(y1, y0); y <= std::max(y1, y0); y++){
      if(x1 >= 0 && x1 < w->resolution->x() && y >= 0 && y < w->resolution->y()){
        w->frameBuffer[y * w->resolution->x() + x1] = (uint32_t)(*this->col);
      }
    }
    return;
  }

  //general case Breseman 
  while(true){
    if(x0 >= 0 && y0 >= 0 && x0 < w->resolution->x() && y0 < w->resolution->y()){
      w->frameBuffer[y0 * w->resolution->x() + x0] = (uint32_t)(*this->col);
    }

    if(x0 == x1 && y0 == y1){
      break;
    }

    int e2 = 2 * err;

    if(e2 > -dy){
      err -= dy;
      x0 += sx;
    }
    if(e2 < dx){
      err += dx;
      y0 += sy;
    }
  }
}


template class Line<int>;
template class Line<float>;
template class Line<double>;
template class Line<char>;
template class Line<uint8_t>;
template class Line<uint16_t>;
template class Line<uint32_t>;
template class Line<uint64_t>;
template class Line<int8_t>;
template class Line<int16_t>;
template class Line<int64_t>;
