#include "DataStruct/Color/Color.h"
#include "Intervalometer/IntMeter.h"
#include "Renderer/Window.h"
#include "Renderer/Renderer.h"
#include "Drawable/Drawable.h"
#include "Shapes/3D/Block/Block.h"
#include <bitset>
#include <cmath>
#include <cstdint>
#include <iostream>
#include "DataStruct/Matrices/Matrix.h"
int main() {
/*  Window* w = new Window();
  w->setPosition(0, 0);
  w->setResolution(400, 400);
  w->setTitle("bogus");
  Renderer* r = new Renderer();
  w->setFPS(-1);
  r->createWindow(w);
  
  IntMeter i;
  i.addExecution([w](){w->printFPS();}, 10e5);
  ColorRGB barva;
  barva.r = 0;
  barva.g = 0;
  barva.b = 0;
 
  for(int i =0; i < 400*400; i++){
    w->frameBuffer[i] = barva; 
  }


  Tri<int>* t = new Tri<int>(200,200,200,300,300,300);
  Tri<int>* t2 =new Tri<int>(200,200,200,100,100,100);
  Tri<int>* t3 =new Tri<int>(200,200,100,200,100,300);
  Tri<int>* t4 =new Tri<int>(229,200,300,200,300,100);
  
  t2->setCol(255,0,0);
  t->setCol(0,255,0);
  t3->setCol(255,255,0);
  t4->setCol(255,0,255);
  t->Draw(w);
  t2->Draw(w);
  t3->Draw(w);
  t4->Draw(w);
  int time = 0;
  i.addExecution([t, t2, t3, t4, time](){
      t->v1->x() = 200 * cos(time);
      t->v1->y() = 200 * sin(time);
      
      t->v2->x() = 200 * cos(time);
      t->v2->y() = 300 * sin(time);

      t->v3->x() = 300    Matrix<T> operator + (const Matrix<T>& other) const;
    Matrix<T> operator - (const Matrix<T>& other) const;
    Matrix<T> operator * (const Matrix<T>& other) const;
    Matrix<T> operator / (const Matrix<T>& other) const;
    Matrix<T> operator = (const Matrix<T>& other) const;
  *  cos(time);
      t->v3->y() = 300 * sin(time);

  }, 10000);
  while(r->running()){
    t->Draw(w);
    time+=1;
  }
  i.clearTimeouts();
 
  std::cout << std::bitset<32>((uint32_t)barva);
*/

  GeneralM<int> bingus(5, 5);
  IdentityM<int> chungus(3, 3,false);
//asdasd
  bingus.set(chungus);
  GeneralM<int> bingus2(3, 3);
  bingus2.set(0,0,5);
  bingus2.set(2,0,5);
  bingus2.set(0,2,5);
  bingus2.set(2,2,5);

  bingus = chungus;
  bingus.print();



  return 0;
}

