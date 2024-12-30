#ifndef VECTOR_H
#define VECTOR_H
#include "../DataStruct/DataStruct.h"
class Vector :  DataStruct{
  public:
    Vector() = default;
    virtual ~Vector() = 0;
    
    virtual float mag();
};
class Vec2D : Vector {
  public:
    float x;
    float y;

};

class Vec3D : Vector{
  public:
    float x;
    float y;
    float z;
  
};

class Vec4D : Vector{
  public:
    float x;
    float y;
    float z;
    float w;
};

#endif


