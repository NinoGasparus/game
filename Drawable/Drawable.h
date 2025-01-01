#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../DataStruct/Color/Color.h"
#include "../DataStruct/Vector/Vector.h"
#include "../Renderer/Renderer.h"
class Drawable{
  private:
  public:
 
    ColorRGB* col;

    Drawable(){}

  virtual void Draw(Renderer* r);
  virtual ~Drawable() {
    delete[] col;
  }

  void setCol(ColorRGB*  color){
     this->col =  color;
  }
 
};



template <typename T>
class Point : Drawable{
  private: 
  public: 
    Vec2D<T> pos; 
    Point(){}  
    Point(T x, T y){
      this->pos.x() = x;
      this->pos.y() = y;
    }
    
    T& x(){ return this->pos.x();};
    T& y(){ return this->pos.y();};

    void Draw(Renderer* r) override;
};

template <typename T>
class Line : Drawable{
  private:
  public:
    Vec4D<T> pos;
    Line();
    Line(T x1, T y1, T x2, T y2){
     this->pos.x() = x1;
     this->pos.y() = y1;
     this->pos.z() = x2;
     this->pos.w() = y2;
    }

  T& x1(){return this->pos.x();};
  T& y1(){return this->pos.y();};   

  T& x2(){return this->pos.z();};
  T& y2(){return this->pos.w();};
 
  void Draw(Renderer* r) override;

};

template <typename T>
class Tri : Drawable{
  private:
  public:
    Vec2D<T> v1;
    Vec2D<T> v2;
    Vec2D<T> v3;
    
    Tri();
    Tri(T x1, T y1, T  x2, T  y2, T x3, T y3){
      this->v1.x() = x1;
      this->v1.y() = y1;
      this->v2.x() = x2;
      this->v2.y() = y2;
      this->v3.x() = x3;
      this->v3.y() = y3;
  }
  Tri(Vec2D<T> v1, Vec2D<T> v2, Vec2D<T> v3){
    this->v1.x() = v1.x();
    this->v1.y() = v1.y();
    this->v2.x() = v2.x();
    this->v2.y() = v2.y();
    this->v3.x() = v3.x();
    this->v3.y() = v3.y();
  }
 /* 
  Vec2D<T>& v1(){return this->v1;};
  Vec2D<T>& v2(){return this->v2;};
  Vec2D<T>& v3(){return this->v3;};
*/
};

#endif // !
