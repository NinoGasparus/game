#ifndef MATRIX_H
#define MATRIX_H

#include "../Vector/Vector.h"

template <typename T>
class Matrix{
  private:
  public:
    Vec2D<int>* size;
    T** data;
    
    Matrix();
    Matrix(int sizeX, int sizeY);
    Matrix(Matrix* m);
    
    virtual void  set(int dimX, int dimY, T value);
    virtual T     get(int dimX, int dimY);
    
};
#endif // !MATRIX_H
