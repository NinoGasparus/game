#include "Vector.h"
#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>

template <typename T>
VecND<T>::VecND(int size) : Vector<T>(size) {
    memset(this->data, 0, size * sizeof(this->data[0])); 
}

template <typename T>
float VecND<T>::mag() const {
    float sqrtsum = 0;
    for (int i = 0; i < this->size; i++) {
        sqrtsum += this->data[i] * this->data[i];
    }
    return std::sqrt(sqrtsum);
}

template <typename T>
void VecND<T>::print() const {
    std::cout << "Vec"<<this->size <<" [\n";
    for (int i = 0; i < this->size; i++) {
        std::cout <<"\tdim" << i << ": " << this->data[i] << ",\n";
    }
  std::cout<< "]\n";
}

template <typename T>
void VecND<T>::normalize() {
    float mag = this->mag();
    for (int i = 0; i < this->size; i++) {
        this->data[i] /= mag;
    }
    return;
}

template <typename T>
void VecND<T>::setDims(T value, int startIndex, int endIndex){
  for(int i = startIndex; i < endIndex; i++){
    this->data[i] = value;
  }
}
template class VecND<int>;
template class VecND<float>;
template class VecND<double>;
template class VecND<char>;
template class VecND<uint8_t>;
template class VecND<uint16_t>;
template class VecND<uint32_t>;
template class VecND<uint64_t>;
template class VecND<int8_t>;
template class VecND<int16_t>;
template class VecND<int64_t>;
