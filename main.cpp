#include "DataStruct/Color/Color.h"
#include "Intervalometer/IntMeter.h"
#include "Renderer/Window.h"
#include "Renderer/Renderer.h"
#include "Drawable/Drawable.h"
#include "Shapes/2D/Triagle/Triangle.h"
#include "Shapes/3D/Block/Block.h"
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>
#include "DataStruct/Matrices/Matrix.h"

#include "Shapes/3D/Mesh/Mesh.h"
#include "bs.h"

int height = 200;
int width = 200;
float fnear = 1.1;
float ffar = 1000;
float fov = 70;
float aspect = (float)height/width;
float fovRad =(float)1/tanf(fov *  0.5/180 * 3.14159);
float dt = 0;
GeneralM<float>* projMat = new GeneralM<float>(4,4);
GeneralM<float>* rotMat = new GeneralM<float>(4,4);

  Window* w = new Window();
int main() {
/*Mesh<float>* cube =  new Mesh<float>();
cube->loadOBJ("dingus2.obj");*/
    

  Block<int>* cube = new Block<int>();
  projMat->set(0,0, aspect*fovRad);
  projMat->set(1,1, fovRad);
  projMat->set(2,2, ffar /(ffar-fnear));
  projMat->set(3,2,(-ffar*fnear) / (ffar-fnear));
  projMat->set(2,3, 1);
  projMat->set(3,3,0);




  Window* w = new Window();
  


  cube->scaleX =1;
  cube->scaleY = 1;
  cube->scaleZ = 1;
  cube->reScale();
  //printf("idk we got here\n");



  /*bs::mulMatVector(cube->tris[0].v1, &triProj->v1,projMat);
     bs::mulMatVector(cube->tris[0].v2, &triProj->v2, projMat);
     bs::mulMatVector(cube->tris[0].v3, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[1].v1, &triProj->v1, projMat);
    bs::mulMatVector(cube->tris[1].v1, &triProj->v2, projMat);
    bs::mulMatVector(cube->tris[1].v1, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[6].v1, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[7].v1, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[8].v1, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[9].v1, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[10].v1, &triProj->v3, projMat);
    bs::mulMatVector(cube->tris[11].v1, &triProj->v3, projMat);
*/
  
  







  w->setPosition(0, 0);
  w->setResolution(width,height);
  w->setTitle("bogus");
  Renderer* r = new Renderer();
  w->setFPS(-1);
  w->borderless = true;
  r->createWindow(w);
 Tri<float> * t[12];
  for(int i =0; i < 12; i++){
    t[i] = new  Tri<float>();
  }
 Triangle<float>* triProj = new Triangle<float>();
 Triangle<float>* triRotated = new Triangle<float>();
 
      t[0]->setCol(255,255,255);
 
  IntMeter i;
  i.addExecution([w](){w->printFPS();}, 10e5);
/*
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
  t4->Draw(w);*/


      Vertex<float> v1rot;
      Vertex<float> v2rot;
      Vertex<float> v3rot;

      Vertex<float> v1trans;
      Vertex<float> v2trans;
      Vertex<float> v3trans;
  ColorRGB barva;
  barva.r = 0;
  barva.g = 0;
  barva.b = 0;
  
  while(r->running()){
 //   t->Draw(w);
    //
    
    w->clear(0x000000FF);
   bs::updateRotMat(rotMat, dt, dt, dt);
  dt += 0.001;
  for(int i =0; i < 12; i++){
    


    v1rot.write(cube->tris[i].v1.x, cube->tris[i].v1.y, cube->tris[i].v1.z);
    v2rot.write(cube->tris[i].v2.x, cube->tris[i].v2.y, cube->tris[i].v2.z);
    v3rot.write(cube->tris[i].v3.x, cube->tris[i].v3.y, cube->tris[i].v3.z);
 
    bs::mulMatVector(v1rot, &triRotated->v1, rotMat);
    bs::mulMatVector(v2rot, &triRotated->v2, rotMat);
    bs::mulMatVector(v3rot, &triRotated->v3, rotMat);

    v1trans.write(triRotated->v1.x, triRotated->v1.y, triRotated->v1.z+3);
    v2trans.write(triRotated->v2.x, triRotated->v2.y, triRotated->v2.z+3);
    v3trans.write(triRotated->v3.x, triRotated->v3.y, triRotated->v3.z+3);


 
    bs::mulMatVector(v1trans, &triProj->v1, projMat);
    bs::mulMatVector(v2trans, &triProj->v2, projMat);
    bs::mulMatVector(v3trans, &triProj->v3,  projMat);

    triProj->v1.write(triProj->v1.x+1, triProj->v1.y+1, triProj->v1.z);
    triProj->v2.write(triProj->v2.x+1, triProj->v2.y+1, triProj->v2.z);
    triProj->v3.write(triProj->v3.x+1, triProj->v3.y+1, triProj->v3.z);

    triProj->v1.x *= (0.5* width);
    triProj->v1.y *= (0.5* height);
    triProj->v2.x *= (0.5* width);
    triProj->v2.y *= (0.5* height);
    triProj->v3.x *= (0.5* width);
    triProj->v3.y *= (0.5* height);


    t[i]->update(triProj);
  }
  for(int i = 0; i < 12; i++){
      t[i]->Draw(w, false);
      t[i]->Draw(w, true);

    }
  }

  w->flip();
  i.clearTimeouts();
 
  return 0;
}

