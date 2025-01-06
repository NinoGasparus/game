#include "Triangle.h"
#include "../../Vertex/Vertex.h"
#include <cstdint>
#include <cstdio>
#include <iostream>

template <typename T>
Triangle<T>::Triangle(){
  this->v1.setZero();
  this->v2.setZero();
  this->v3.setZero();
}

template <typename T>
Triangle<T>::Triangle(Vertex<T> v1, Vertex<T> v2, Vertex<T> v3){
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;
}


template <typename T>
void Triangle<T>::scale(T scale){
  this->v1.scale(scale);
  this->v2.scale(scale);
  this->v3.scale(scale);
};

template <typename T>
void Triangle<T>::scale(T scaleX, T scaleY, T scaleZ){
  this->v1.scale(scaleX, scaleY, scaleZ);
  this->v2.scale(scaleX, scaleY, scaleZ);
  this->v3.scale(scaleX, scaleY, scaleZ);

};

template <typename T>
void Triangle<T>::scale(T scale, short vertexID){
  switch (vertexID) {
    case 0:
      this->v1.scale(scale);break;
    case 1:
      this->v2.scale(scale);break;
    case 2:
      this->v3.scale(scale);break;
    default:
      printf("triangle vertex acess out of range %i", vertexID);
  }
};

template <typename T>
void Triangle<T>::scale(T scaleX, T scaleY, T scaleZ, short vertexID){
  switch (vertexID) {
    case 0:
      this->v1.scale(scaleX, scaleY, scaleZ);break;
    case 1:
      this->v2.scale(scaleX, scaleY, scaleZ);break;
    case 2:
      this->v3.scale(scaleX, scaleY, scaleZ);break;
    default:
      printf("triangle vertex acess out of range %i", vertexID);
  }
};


template class Triangle<int>;
template class Triangle<float>;
template class Triangle<double>;
template class Triangle<char>;
template class Triangle<uint8_t>;
template class Triangle<uint16_t>;
template class Triangle<uint32_t>;
template class Triangle<uint64_t>;
template class Triangle<int8_t>;
template class Triangle<int16_t>;
template class Triangle<int64_t>;

