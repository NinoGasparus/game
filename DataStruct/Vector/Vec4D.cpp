#include "Vector.h"
#include <cmath>

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
    printf("Vec4 [x: %f, y: %f, z: %f, w: %f]", this->data[0], this->data[1], this->data[2], this->data[3]);
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

