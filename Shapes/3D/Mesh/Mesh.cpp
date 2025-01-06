#include "Mesh.h"
#include <cstdint>

template <typename T>
Mesh<T>::Mesh(int64_t triCount){
  this->tris = new Triangle<T>[triCount];
}

template <typename T>
Mesh<T>::~Mesh(){
  delete[] this->tris;
}


template class Mesh<int>;
template class Mesh<float>;
template class Mesh<double>;
template class Mesh<char>;
template class Mesh<uint8_t>;
template class Mesh<uint16_t>;
template class Mesh<uint32_t>;
template class Mesh<uint64_t>;
template class Mesh<int8_t>;
template class Mesh<int16_t>;
template class Mesh<int64_t>;
