#include "Vector.h"
#include <cmath>
#include <cstdio>
template <typename T>
Vec2D<T>::Vec2D() : Vector<T>(2){
  this->data[0] = 0;
  this->data[1] = 0;
}

template <typename T>
float Vec2D<T>::mag() const{ 
  return std::sqrtf(this->data[0]* this->data[0]   + this->data[1]* this->data[1]);
}




template <typename T>
void Vec2D<T>::print() const{
  printf("Vec2 [x: %f, y: %f]",this->data[0],this->data[1]);
}

template <typename T>
void  Vec2D<T>::normalize() {
  float mag = this->mag();
  this->data[0] /= mag;
  return;
}
