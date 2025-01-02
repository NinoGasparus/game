#ifndef VECTOR_H
#define VECTOR_H
#include "../DataStruct/DataStruct.h"
#include <cstdio>

template <typename T>
class Vector : public DataStruct<T>{
  protected:
  public:
    char checksum = -1;
    Vector(int size) : DataStruct<T>(size){} 
    
    virtual float mag() const{
      return 0;
    };
    
    virtual void print() const{
      printf("Vector at %p\n", this->data );
    }

    virtual void  normalize() = 0;
};


//pro bass shop

template <typename  T>
class Vec2D :  Vector<T> {
  private:
  public:
    char checksum = 2;
    Vec2D<T>();
    T& x(){ return this->data[0];};
    T& y(){ return this->data[1];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;
};





template <typename T>
class Vec3D : Vector<T>{
  private:
  public:
    char checksum = 3;
    Vec3D<T>();
    T& x(){ return this->data[0];};
    T& y(){ return this->data[1];};
    T& z(){ return this->data[2];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;

};


template <typename T>
class Vec4D : Vector<T>{
  private:
  public:
  Vec4D<T>();
    char checksum = 4;
    T& x(){ return this->data[0];};
    T& y(){ return this->data[1];};
    T& z(){ return this->data[2];};
    T& w(){ return this->data[3];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;


};

template <typename T>
class VecND : Vector<T>{
  private:
  public:
    char checksum = 5;
    VecND(int size);
    T& dim(int dim){ return this->data[dim];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;
    
    void setDims(T value, int startIndex, int endIndex);
};



#endif


