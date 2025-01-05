#include "Drawable.h"
#include "../DataStruct/Color/Color.h"

Drawable::Drawable(){
      this->col = new ColorRGB();
}


void  Drawable::setCol(ColorRGB* color){
      delete col;
      this->col = color;
 /*     this->col->r =  color->r;
      this->col->g = color->g;
      this->col->b = color->b;*/
 
}

void Drawable::setCol(int r,  int  g, int b){
  this->col->r = r;
  this->col->g = g;
  this->col->b = b;
}

Drawable::~Drawable(){
     delete col;
}
 
