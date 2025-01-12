#ifndef BLOCK_H
#define BLOCK_H

#include "../Mesh/Mesh.h"
template <typename T>
class Block : public Mesh<T>{
  private:
  public:
    int scaleX;
    int scaleY;
    int scaleZ;
  
    Block();

    void reScale();
    

};
#endif // !BLOCK_H
