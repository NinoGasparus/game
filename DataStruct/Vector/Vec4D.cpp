#include "Vector.h"
#include <cmath>
#include <cstdint>
#include <iostream>

template <typename T>
Vec4D<T>::Vec4D() : Vector<T>(4) {
    this->data[0] = 0;
    this->data[1] = 0;
    this->data[2] = 0;
    this->data[3] = 0;
}

template <typename T>
float Vec4D<T>::mag() const {
    return std::sqrtf(
        this->data[0] * this->data[0] + 
        this->data[1] * this->data[1] + 
        this->data[2] * this->data[2] + 
        this->data[3] * this->data[3]
    );
}

template <typename T>
void Vec4D<T>::print() const {
  std::cout << "Vec2 [x: " << this->data[0]  << " y: " << this->data[1] << " z: " << this->data[2] << " w: " << this->data[3] << "]\n";
}

template <typename T>
void Vec4D<T>::normalize() {
    float mag = this->mag();
    this->data[0] /= mag;
    this->data[1] /= mag;
    this->data[2] /= mag;
    this->data[3] /= mag;
    return;
}

template class Vec4D<int>;
template class Vec4D<float>;
template class Vec4D<double>;
template class Vec4D<char>;
template class Vec4D<uint8_t>;
template class Vec4D<uint16_t>;
template class Vec4D<uint32_t>;
template class Vec4D<uint64_t>;
template class Vec4D<int8_t>;
template class Vec4D<int16_t>;
template class Vec4D<int64_t>;
