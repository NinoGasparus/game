#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../DataStruct/Color/Color.h"

class Drawable{
  private:
  public:
    Color* buff;
    Drawable(){}
    Drawable(int size){
      buff = new Color[size];
    }

  virtual ~Drawable() {
    delete[] buff;
  }


};

class Point : Drawable{
  private: 
  public: 
    float x = 0;
    float y = 0;
    ColorRGB col;

    Point() : Drawable(1) {}  
    Point(int x, int y) : Drawable(1){
      this->x = x;
      this->y = y;
    }
    void setCol(ColorRGB  color){
      this->col =  color;
    }
    
  
};

#endif // !
