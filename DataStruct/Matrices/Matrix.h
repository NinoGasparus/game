#ifndef MATRIX_H
#define MATRIX_H

#include "../Vector/Vector.h"

template <typename T>
class Matrix{
  protected:
    T** data;
  public:
    Vec2D<int>* size;
    Matrix();
    Matrix(int sizeX, int sizeY);
    Matrix(Matrix* m) ;
    
    virtual void    set(int dimX, int dimY, T value);
    virtual void    set(Matrix<T> matrix);
    virtual T       get(int dimX, int dimY);
    
    void print();
    ~Matrix();
};

template <typename T>
class SquareM : public Matrix<T>{
  private:
  public:
   SquareM(int sizeXY);
    SquareM(Matrix<T>* m);
};


template <typename T>
class GeneralM : public Matrix<T>{
  private:
  public:
   GeneralM(int sizeXY);
    GeneralM(int sizeX, int sizeY);
  

};


template <typename T>
class IdentityM :public SquareM<T>{
  private:
    void set(int dimX, int dimY, T value);
  public:
    IdentityM(int sizeXY);
    IdentityM(int sizeXY, bool flipped);

    IdentityM(int sizeXY, T value);
    IdentityM(int sizeXY, T value, bool flipped);
};
#endif // !MATRIX_H
