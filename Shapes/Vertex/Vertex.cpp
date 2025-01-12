#include "Vertex.h"
#include <cstdint>

template <typename  T>
Vertex<T>::Vertex(){
  this->x = 0;
 this-> y = 0;
 this-> z = 0;
}

template <typename T>
Vertex<T>::Vertex(T x, T y, T z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

template <typename  T>
void Vertex<T>::setZero(){
  x =0;
  y = 0;
  z = 0;
}

template  <typename T>
void Vertex<T>::scale(T scale){
  x *= scale;
  y *= scale;
  z *= scale;
}

template <typename T>
void Vertex<T>::scale(T scaleX, T scaleY, T scaleZ){
  x *= scaleX;
  y *= scaleY;
  z *= scaleZ;
}
template <typename T>
Vertex<T>::~Vertex(){

}

template <typename T>
void Vertex<T>::write(T x, T y, T z){
  this->x = x;
  this->y = y;
  this->z = z;

}

template class Vertex<int>;
template class Vertex<float>;
template class Vertex<double>;
template class Vertex<char>;
template class Vertex<uint8_t>;
template class Vertex<uint16_t>;
template class Vertex<uint32_t>;
template class Vertex<uint64_t>;
template class Vertex<int8_t>;
template class Vertex<int16_t>;
template class Vertex<int64_t>;
