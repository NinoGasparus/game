#ifndef COLOR_H
#define COLOR_H


#include <cstdint>
class Color{
  public:
    Color(){}
  
  virtual operator uint32_t() const =0;

  virtual ~Color(){}
};

 //for it to work 

class ColorRGB : public Color{
  private:
  public:
  unsigned    char r  = 255;
  unsigned    char g  = 0;
  unsigned    char b  = 255;
  
  ColorRGB(){};
  ColorRGB(unsigned char r, unsigned char g, unsigned char b){
    this->r = r;
    this->g = g;
    this->b = b;
  }
    
  operator uint32_t()const override;
};

class ColorRGBA : public ColorRGB{
  private:
  public:
  unsigned    char a = 255;
  
  ColorRGBA(){};
  ColorRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
  }

  operator uint32_t() const override;
};
class ColorHSB : public Color{
  private:
  public:
  unsigned    char h  = 0;
  unsigned    char s  = 0;
  unsigned    char b  = 255;

  ColorHSB(){};
  ColorHSB(unsigned char h, unsigned char s, unsigned char b){
    this->h = h;
    this->s = s;
    this->b = b;
  }
  
  operator uint32_t() const override;
};
#endif // !COLOR_H

