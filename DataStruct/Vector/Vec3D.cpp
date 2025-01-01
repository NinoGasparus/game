#include "Vector.h"
#include <cmath>
#include <cstdint>
#include <iostream>

template <typename T>
Vec3D<T>::Vec3D() : Vector<T>(3) { 
    this->data[0] = 0;
    this->data[1] = 0;
    this->data[2] = 0;  
}

template <typename T>
float Vec3D<T>::mag() const {
    return std::sqrtf(this->data[0] * this->data[0] + this->data[1] * this->data[1] + this->data[2] * this->data[2]);
}

template <typename T>
void Vec3D<T>::print() const {
  std::cout << "Vec2 [x: " << this->data[0]  << " y: " << this->data[1] << " z: " << this->data[2] << "]\n";
}

template <typename T>
void Vec3D<T>::normalize() {
    float mag = this->mag();    
    this->data[0] /= mag;
    this->data[1] /= mag;
    this->data[2] /= mag;
    return;
}

template class Vec3D<int>;
template class Vec3D<float>;
template class Vec3D<double>;
template class Vec3D<char>;
template class Vec3D<uint8_t>;
template class Vec3D<uint16_t>;
template class Vec3D<uint32_t>;
template class Vec3D<uint64_t>;
template class Vec3D<int8_t>;
template class Vec3D<int16_t>;
template class Vec3D<int64_t>;
