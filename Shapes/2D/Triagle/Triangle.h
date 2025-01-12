#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "../../Vertex/Vertex.h"
    
template <typename T>
class Triangle{
  private:
  public:
    Vertex<T> v1;
    Vertex<T> v2;
    Vertex<T> v3;

  //fix
  Triangle<T>();
    
    void scale(T scale);
    void scale(T scaleX, T scaleY, T scaleZ);
    void scale(T scale, short vertexID);
    void scale(T scaleX, T scaleY, T scaleZ, short vertexID);

  Triangle<T>(Vertex<T> v1, Vertex<T> v2, Vertex<T> v3);

};
#endif // !TRIANGLE_H
