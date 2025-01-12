#include "Block.h"
#include <cstdint>



template  <typename T>
Block<T>::Block() : Mesh<T>(12){
  this->scaleX = 1;
  this->scaleY = 1;
  this->scaleZ = 1;
  this->triangleCount = 12;
  this->vertexCount = 8;

/*
float cubeData[8][3] = {
  {1.f, 1.f, 1.f},//0
  {-1.f, 1.f, 1.f},//1
  {-1.f, 1.f, -1.f},
  {1.f, 1.f, -1.f},	//3
  {1.f, -1.f, 1.f},	//4
  {-1.f, -1.f, 1.f},	//5
  {-1.f, -1.f, -1.f},	//6
  {1.f, -1.f, -1.f}	//7
};*/

float cubeData[8][3] = {
    {0,  0, 0 },
    {1, 0, 0 },
    {1, 1, 0}, 
    {0, 1, 0},
    {0, 0, 1}, 
    {1, 0, 1},
    {1, 1, 1},
    {0, 1, 1}
  };


int  indices[12][3] ={
  {0, 1, 2},
  {0, 2, 3},
  {1, 5, 6},
  {1, 6, 2},
  {5, 4, 7},
  {5, 7, 6},
  {4, 0, 3},
  {4, 3, 7},
  {0, 1, 5},
  {0, 5, 4},
  {3, 2, 6},
  {3, 6, 7}
};

  /*
int indices[12][3] =
{
  {0, 1, 3}, //top 1
  {3, 1, 2}, //top 2
  {2, 6, 7}, //front 1
  {7, 3, 2}, //front 2
  {7, 6, 5}, //bottom 1
  {5, 4, 7}, //bottom 2
  {5, 1, 4}, //back 1
  {4, 1, 0}, //back 2
  {4, 3, 7}, //right 1
  {3, 4, 0}, //right 2
  {5, 6, 2}, //left 1
  {5, 1, 2} // left2
};*/
for (int i = 0; i < 12; i++) {
    this->tris[i].v1.write(cubeData[indices[i][0]][0], cubeData[indices[i][0]][1], cubeData[indices[i][0]][2]);
    this->tris[i].v2.write(cubeData[indices[i][1]][0], cubeData[indices[i][1]][1], cubeData[indices[i][1]][2]);
    this->tris[i].v3.write(cubeData[indices[i][2]][0], cubeData[indices[i][2]][1], cubeData[indices[i][2]][2]);
}

}

template  <typename  T>
void Block<T>::reScale(){
for(int i = 0; i < 12; i++){
    this->tris[i].scale(this->scaleX, this->scaleY, this->scaleZ);
  }
}
template class Block<int>;
template class Block<float>;
template class Block<double>;
template class Block<char>;
template class Block<uint8_t>;
template class Block<uint16_t>;
template class Block<uint32_t>;
template class Block<uint64_t>;
template class Block<int8_t>;
template class Block<int16_t>;
template class Block<int64_t>;
