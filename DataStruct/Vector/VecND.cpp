#include "Vector.h"
#include <cmath>
#include <cstring>


VecND::VecND(int size) : Vector(size){
  memset(data, 0, size * sizeof(data[0]));
}

float VecND::mag() const{
  float sqrtsum= 0;
  for(int i =0; i < this->size; i++){
    sqrtsum+= data[i] * data[i];
  }
  return std::sqrtf(sqrtsum);
}
void VecND::print() const{
  printf("Vec%i [\n", this->size);
  for(int i =0; i < this->size; i++){
    printf("\tdim%i: %f,\n", i, data[i]);
  }
  printf("]\n");
}

void  VecND::normalize() {
  float mag = this->mag();
  for(int i =0; i < this->size; i++){
    data[i] /= mag;
  }
  return;
}
