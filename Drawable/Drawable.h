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

  virtual void Draw(Renderer r);
  virtual ~Drawable() {
    delete[] col;
  }

  void setCol(ColorRGB*  color){
     this->col =  color;
  }
 
};

class Point : Drawable{
  private: 
  public: 
    Vec2D<int> pos; 
    Point(){}  
    Point(int x, int y){
      this->pos.x() = x;
      this->pos.y() = y;
    }
    
    int& x(){ return this->pos.x();};
    int& y(){ return this->pos.y();};

    void Draw(Renderer r) override;
};

class Line : Drawable{
  private:
  public:
    Vec4D<int> pos;
    Line();
    Line(int x1, int y1, int x2, int y2){
     this->pos.x() = x1;
     this->pos.y() = y1;
     this->pos.z() = x2;
     this->pos.w() = y2;
    }

  int& x1(){return this->pos.x();};
  int& y1(){return this->pos.y();};   

  int& x2(){return this->pos.z();};
  int& y2(){return this->pos.w();};
};

#endif // !
