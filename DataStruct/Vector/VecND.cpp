#include "Vector.h"
#include <cmath>
#include <cstring>


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
    return std::sqrtf(sqrtsum);
}

template <typename T>
void VecND<T>::print() const {
    printf("Vec%i [\n", this->size);
    for (int i = 0; i < this->size; i++) {
        printf("\tdim%i: %f,\n", i, this->data[i]);
    }
    printf("]\n");
}

template <typename T>
void VecND<T>::normalize() {
    float mag = this->mag();
    for (int i = 0; i < this->size; i++) {
        this->data[i] /= mag;
    }
    return;
}

