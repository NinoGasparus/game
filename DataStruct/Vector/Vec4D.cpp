#include "Vector.h"
#include <cmath>


Vec4D::Vec4D() : Vector(4){
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
  data[3] = 0;
}

float Vec4D::mag() const{
  return std::sqrtf(data[0] * data[0] + data[1] * data[1] + data[2]* data[2] + data[3] * data[3]);
}
void Vec4D::print() const{
  printf("Vec4 [x: %f, y: %f, z: %f, w: %f]",data[0], data[1], data[2], data[3]);
}

void  Vec4D::normalize() {
  float mag = this->mag();
  data[0] /= mag;
  data[1] /= mag;
  data[2] /= mag;
  data[3] /= mag;
  return;
}
