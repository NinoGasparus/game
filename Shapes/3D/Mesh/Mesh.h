#ifndef MESH_H
#define MESH_H

#include "../../2D/Triagle/Triangle.h"
#include <cstdint>
#include <string>

template  <typename T>
class Mesh{
  private:
  public:
    Triangle<T>* tris = nullptr;
    int triangleCount = 0;
    int vertexCount = 0;
    
    int scaleX = 1;
    int scaleY = 1;
    int scaleZ = 1;

    Mesh();
    Mesh(int64_t triCount);
  
    void loadOBJ(std::string filename);
    void reScale();
    ~Mesh();
};

#endif // !MESH_H

