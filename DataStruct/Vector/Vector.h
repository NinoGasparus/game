#ifndef VECTOR_H
#define VECTOR_H
#include "../DataStruct/DataStruct.h"
#include <cstdio>


class Vector : public DataStruct{
  protected:
  public:
    Vector(int size) : DataStruct(size){}
    
    virtual float mag() const{
      return 0;
    };
    
    virtual void print() const{
      printf("Vector at %p\n", data );
    }

    virtual void  normalize() = 0;
};


//pro bass shop



class Vec2D :  Vector {
  private:
  public:
    Vec2D();
    float& x(){ return data[0];};
    float& y(){ return data[1];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;
};







class Vec3D : Vector{
  private:
  public:
    Vec3D();
    float& x(){ return data[0];};
    float& y(){ return data[1];};
    float& z(){ return data[2];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;

};



class Vec4D : Vector{
  private:
  public:
    Vec4D();
    float& x(){ return data[0];};
    float& y(){ return data[1];};
    float& z(){ return data[2];};
    float& w(){ return data[3];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;


};

class VecND : Vector{
  private:
  public:
    VecND(int size);
    float& dim(int dim){ return data[dim];};

    float mag() const   override;
    void print() const  override;
    void normalize()    override;
};



#endif


