#ifndef MESH_H
#define MESH_H

#include "../../2D/Triagle/Triangle.h"
#include <cstdint>

template  <typename T>
class Mesh{
  private:
  public:
    Triangle<T>* tris = nullptr;

    Mesh(int64_t triCount);
    ~Mesh();
};

#endif // !MESH_H

