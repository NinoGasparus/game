#include "Vector.h"
#include <cmath>
#include <cstdio>

Vec2D::Vec2D() : Vector(2){
  data[0] = 0;
  data[1] = 0;
}


float Vec2D::mag() const{ 
  return std::sqrtf(data[0]*data[0]   + data[1]* data[1]);
}

void Vec2D::print() const{
  printf("Vec2 [x: %f, y: %f]",data[0], data[1]);
}

void  Vec2D::normalize() {
  return;
}
