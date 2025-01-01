#include "Vector.h"
#include <cmath>
#include <cstdint>
#include <iostream>

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
  std::cout << "Vec2 [x: " << this->data[0]  << " y: " << this->data[1] << "]\n";
}

template <typename T>
void  Vec2D<T>::normalize() {
  float mag = this->mag();
  this->data[0] /= mag;
  this->data[1] /= mag;
  return;
}

template class Vec2D<int>;
template class Vec2D<float>;
template class Vec2D<double>;
template class Vec2D<char>;
template class Vec2D<uint8_t>;
template class Vec2D<uint16_t>;
template class Vec2D<uint32_t>;
template class Vec2D<uint64_t>;
template class Vec2D<int8_t>;
template class Vec2D<int16_t>;
template class Vec2D<int64_t>;
