#include "Vector.h"
#include <cmath>


Vec3D::Vec3D() : Vector(3){
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;  
}
  
float Vec3D::mag() const {
  return std::sqrtf(data[0] * data[0] + data[1] * data[1] * data[2] * data[2]);
}


void Vec3D::print() const{
  printf("Vec3 [x: %f, y: %f, z: %f]",data[0], data[1], data[2]);
}

void  Vec3D::normalize() {
  float mag = this->mag();    
  data[0] /= mag;
  data[1] /= mag;
  data[2] /= mag;
  return;
}
