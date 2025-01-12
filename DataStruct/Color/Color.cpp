#include "Color.h"
#include <cmath>
#include <cstdint>


ColorRGB::operator uint32_t() const {
  uint32_t v = 0;
  v |= this->r;
  v = v<<8;
  v |= this->g;
  v = v<<8;
  v |= this->b;
  v = v<<8;
  v |=  255;
  
  return v;
}

ColorRGBA::operator uint32_t() const{
  uint32_t v = 0;
  v |= this->r;
  v = v<<8;
  v |= this->g;
  v = v<<8;
  v |= this->b;
  v = v<<8;
  v |= this->a;
 
  return v;
}
ColorHSB::operator uint32_t() const{
  //standard hsb conversion. dont use hsb cuz yes. 
  float C = this->b* this->s;
  float H_prime = this->h/ 60.0f;
  float X = C * (1 - std::fabs(fmod(H_prime, 2) - 1));
  float m = this->b- C;

  float r, g, b;
  if(0 <= H_prime && H_prime < 1){
    r = C; g = X; b = 0;
  }else if(1 <= H_prime && H_prime < 2){
    r = X; g = C; b = 0;
  }else if(2 <= H_prime && H_prime < 3){
    r = 0; g = C; b = X;
  }else if(3 <= H_prime && H_prime < 4){
    r = 0; g = X; b = C;
  }else if(4 <= H_prime && H_prime < 5) {
    r = X; g = 0; b = C;
  }else if(5 <= H_prime && H_prime < 6){
    r = C; g = 0; b = X;
  }else{
    r = 0; g = 0; b = 0;
  }

    char R =(int)((r + m) * 255);
    char G =(int)((g + m) * 255);
    char B =(int)((b + m) * 255);

  uint32_t v = 0;
  v |= R;
  v = v<<8;
  v |= G;
  v = v<<8;
  v |=B;
  v = v<<8;
  v |=  255;
 
  return v;
}
