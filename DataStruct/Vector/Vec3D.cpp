#include "Vector.h"
#include <cmath>


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
    printf("Vec3 [x: %f, y: %f, z: %f]", this->data[0], this->data[1], this->data[2]);
}

template <typename T>
void Vec3D<T>::normalize() {
    float mag = this->mag();    
    this->data[0] /= mag;
    this->data[1] /= mag;
    this->data[2] /= mag;
    return;
}

