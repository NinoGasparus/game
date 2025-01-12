#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../DataStruct/Color/Color.h"
#include "../DataStruct/Vector/Vector.h"
#include "../Renderer/Window.h"
#include "../Shapes/2D/Triagle/Triangle.h"
class Drawable{
  private:
  public:
 
    ColorRGB* col;

    Drawable();
    virtual void Draw(Window* w) = 0;
    void setCol(ColorRGB*  color);
    void setCol(int r,  int  g, int b);
    ~Drawable();
    
};



template <typename T>
class Point : public Drawable{
  private: 
  public: 
    Vec2D<T>* pos; 
    Point() : Drawable() {
      this->pos = new Vec2D<T>();  
    }; 

    Point(T x, T y) : Drawable() {
      this->pos = new Vec2D<T>();
      this->pos->x() = x;
      this->pos->y() = y;
    };
    
    T& x(){ return this->pos->x();};
    T& y(){ return this->pos->y();};
    
    void Draw(Window* w) override;
    
    ~Point(){
      delete pos;
    }
};

template <typename T>
class Line : public  Drawable{
  private:
  public:
    Vec4D<T>* pos;
    Line() : Drawable(){
      this->pos = new Vec4D<T>();
    };
    Line(T x1, T y1, T x2, T y2) : Drawable(){
     this->pos = new Vec4D<T>();

     this->pos->x() = x1;
     this->pos->y() = y1;
     this->pos->z() = x2;
     this->pos->w() = y2;
    }

    T& x1(){return this->pos->x();};
    T& y1(){return this->pos->y();};   

    T& x2(){return this->pos->z();};
    T& y2(){return this->pos->w();};
 
    void Draw(Window* w) override;
    
    ~Line(){
      delete this->pos;
  }
};

template <typename T>
class Tri : public Drawable{
  private:
  public:
    Vec2D<T>* v1;
    Vec2D<T>* v2;
    Vec2D<T>* v3;
    
    Tri() : Drawable(){
      this->v1 = new Vec2D<T>();
      this->v2 = new Vec2D<T>();
      this->v3 = new Vec2D<T>();
    }
    Tri(T x1, T y1, T  x2, T  y2, T x3, T y3) : Drawable() {
      this->v1 = new Vec2D<T>();
      this->v2 = new Vec2D<T>();
      this->v3 = new Vec2D<T>();

      this->v1->x() = x1;
      this->v1->y() = y1;
      this->v2->x() = x2;
      this->v2->y() = y2;
      this->v3->x() = x3;
      this->v3->y() = y3;
    }
    Tri(Vec2D<T>* v1, Vec2D<T>* v2, Vec2D<T>* v3) : Drawable(){
      this->v1 = new Vec2D<T>();
      this->v2 = new Vec2D<T>();
      this->v3 = new Vec2D<T>();

      this->v1->x() = v1->x();
      this->v1->y() = v1->y();
      this->v2->x() = v2->x();
      this->v2->y() = v2->y();
      this->v3->x() = v3->x();
      this->v3->y() = v3->y();
    }
    //fix
    Tri(Triangle<T> tri) {
    this->v1->x() = tri.v1.x;
    this->v1->y() = tri.v1.y;

    this->v2->x() = tri.v2.x;
    this->v2->y() = tri.v2.y;

    this->v3->x() = tri.v3.x;
    this->v3->y() = tri.v3.y;
    }
    Tri(Triangle<T>* tri) {
    this->v1->x() = tri->v1.x;
    this->v1->y() = tri->v1.y;

    this->v2->x() = tri->v2.x;
    this->v2->y() = tri->v2.y;

    this->v3->x() = tri->v3.x;
    this->v3->y() = tri->v3.y;
    }

    void update(Triangle<T> tri){
this->v1->x() = tri.v1.x;
    this->v1->y() = tri.v1.y;

    this->v2->x() = tri.v2.x;
    this->v2->y() = tri.v2.y;

    this->v3->x() = tri.v3.x;
    this->v3->y() = tri.v3.y;

  }
  void update(Triangle<T>* tri) {
    this->v1->x() = tri->v1.x;
    this->v1->y() = tri->v1.y;

    this->v2->x() = tri->v2.x;
    this->v2->y() = tri->v2.y;

    this->v3->x() = tri->v3.x;
    this->v3->y() = tri->v3.y;
    }


    void Draw(Window* w, bool fill); 
    void Draw(Window* w) override;
    ~Tri(){
      delete this->v1;
      delete this->v2;
      delete this->v3;
    }
};
#endif // !
