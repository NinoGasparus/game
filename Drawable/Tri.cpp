#include "Drawable.h"
#include "../Renderer/Window.h"


template <typename T>
void Tri<T>::Draw(Window* w){
  this->Draw(w, true);
}

template <typename T>
void Tri<T>::Draw(Window* w, bool fill) {
  int x1 = (int)(this->v1->x());
  int y1 = (int)(this->v1->y());
  int x2 = (int)(this->v2->x());
  int y2 = (int)(this->v2->y());
  int x3 = (int)(this->v3->x());
  int y3 = (int)(this->v3->y());

  if (y1 > y2){ std::swap(x1, x2); std::swap(y1, y2);}
  if (y2 > y3){ std::swap(x2, x3); std::swap(y2, y3);}
  if (y1 > y2){ std::swap(x1, x2); std::swap(y1, y2);}

  float slope1 = (y2-y1) != 0 ? (x2 - x1) / (float)(y2 - y1) : 0;  
  float slope2 = (y3-y2) != 0 ? (x3 - x2) / (float)(y3 - y2) : 0;  
  float slope3 = (y3-y1) != 0 ? (x3 - x1) / (float)(y3 - y1) : 0;

  if(fill){
    for(int y = y1; y <= y3; y++){
      int xStart = x1 + slope1 * (y - y1);
      int xEnd = x1 + slope3 * (y - y1);

      if(y >= y2){
        xStart = x2 + slope2 * (y - y2);
      }

      xStart = std::max(xStart, 0);
      xEnd = std::min(xEnd, w->resolution->x() - 1);

      for(int x = xStart; x <= xEnd; x++){
        if(x >= 0 && x < w->resolution->x() && y >= 0 && y < w->resolution->y()){
          w->frameBuffer[y*w->resolution->x()+x] = (uint32_t)(*this->col);
        }
      }
    }
  }else{
    Line<T> edge1(x1, y1, x2, y2);
    Line<T> edge2(x2, y2, x3, y3);
    Line<T> edge3(x3, y3, x1, y1);
    edge1.Draw(w);
    edge2.Draw(w);
    edge3.Draw(w);
  }
}

template class Tri<int>;
template class Tri<float>;
template class Tri<double>;
template class Tri<char>;
template class Tri<uint8_t>;
template class Tri<uint16_t>;
template class Tri<uint32_t>;
template class Tri<uint64_t>;
template class Tri<int8_t>;
template class Tri<int16_t>;
template class Tri<int64_t>;
