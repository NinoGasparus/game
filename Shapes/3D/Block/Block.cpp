#include "Block.h"
#include <cstdint>

template <typename T>
Block<T>::Block() : Mesh<T>(12){
  

// Front 
this->tris[0].v1.setZero(); // (0, 0, 0)
this->tris[0].v2.x = 1; this->tris[0].v2.y = 0; this->tris[0].v2.z = 0; // (1, 0, 0)
this->tris[0].v3.x = 0; this->tris[0].v3.y = 1; this->tris[0].v3.z = 0; // (0, 1, 0)

this->tris[1].v1.x = 1; this->tris[1].v1.y = 0; this->tris[1].v1.z = 0; // (1, 0, 0)
this->tris[1].v2.x = 1; this->tris[1].v2.y = 1; this->tris[1].v2.z = 0; // (1, 1, 0)
this->tris[1].v3.x = 0; this->tris[1].v3.y = 1; this->tris[1].v3.z = 0; // (0, 1, 0)

// Right 
this->tris[2].v1.x = 1; this->tris[2].v1.y = 0; this->tris[2].v1.z = 0; // (1, 0, 0)
this->tris[2].v2.x = 1; this->tris[2].v2.y = 1; this->tris[2].v2.z = 0; // (1, 1, 0)
this->tris[2].v3.x = 1; this->tris[2].v3.y = 0; this->tris[2].v3.z = 1; // (1, 0, 1)

this->tris[3].v1.x = 1; this->tris[3].v1.y = 0; this->tris[3].v1.z = 1; // (1, 0, 1)
this->tris[3].v2.x = 1; this->tris[3].v2.y = 1; this->tris[3].v2.z = 0; // (1, 1, 0)
this->tris[3].v3.x = 1; this->tris[3].v3.y = 1; this->tris[3].v3.z = 1; // (1, 1, 1)

// Top
this->tris[4].v1.x = 0; this->tris[4].v1.y = 1; this->tris[4].v1.z = 0; // (0, 1, 0)
this->tris[4].v2.x = 1; this->tris[4].v2.y = 1; this->tris[4].v2.z = 0; // (1, 1, 0)
this->tris[4].v3.x = 0; this->tris[4].v3.y = 1; this->tris[4].v3.z = 1; // (0, 1, 1)

this->tris[5].v1.x = 1; this->tris[5].v1.y = 1; this->tris[5].v1.z = 0; // (1, 1, 0)
this->tris[5].v2.x = 1; this->tris[5].v2.y = 1; this->tris[5].v2.z = 1; // (1, 1, 1)
this->tris[5].v3.x = 0; this->tris[5].v3.y = 1; this->tris[5].v3.z = 1; // (0, 1, 1)

// Back
this->tris[6].v1.x = 1; this->tris[6].v1.y = 0; this->tris[6].v1.z = 1; // (1, 0, 1)
this->tris[6].v2.x = 0; this->tris[6].v2.y = 0; this->tris[6].v2.z = 1; // (0, 0, 1)
this->tris[6].v3.x = 1; this->tris[6].v3.y = 1; this->tris[6].v3.z = 1; // (1, 1, 1)

this->tris[7].v1.x = 0; this->tris[7].v1.y = 0; this->tris[7].v1.z = 1; // (0, 0, 1)
this->tris[7].v2.x = 0; this->tris[7].v2.y = 1; this->tris[7].v2.z = 1; // (0, 1, 1)
this->tris[7].v3.x = 1; this->tris[7].v1.y = 1; this->tris[7].v3.z = 1; // (1, 1, 1)

// Left
this->tris[8].v1.x = 0; this->tris[8].v1.y = 0; this->tris[8].v1.z = 0; // (0, 0, 0)
this->tris[8].v2.x = 0; this->tris[8].v2.y = 0; this->tris[8].v2.z = 1; // (0, 0, 1)
this->tris[8].v3.x = 0; this->tris[8].v3.y = 1; this->tris[8].v3.z = 0; // (0, 1, 0)

this->tris[9].v1.x = 0; this->tris[9].v1.y = 0; this->tris[9].v1.z = 1; // (0, 0, 1)
this->tris[9].v2.x = 0; this->tris[9].v2.y = 1; this->tris[9].v2.z = 1; // (0, 1, 1)
this->tris[9].v3.x = 0; this->tris[9].v3.y = 1; this->tris[9].v3.z = 0; // (0, 1, 0)

// Bottom
this->tris[10].v1.x = 0; this->tris[10].v1.y = 0; this->tris[10].v1.z = 0; // (0, 0, 0)
this->tris[10].v2.x = 1; this->tris[10].v2.y = 0; this->tris[10].v2.z = 0; // (1, 0, 0)
this->tris[10].v3.x = 0; this->tris[10].v3.y = 0; this->tris[10].v3.z = 1; // (0, 0, 1)

this->tris[11].v1.x = 1; this->tris[11].v1.y = 0; this->tris[11].v1.z = 0; // (1, 0, 0)
this->tris[11].v2.x = 1; this->tris[11].v2.y = 0; this->tris[11].v2.z = 1; // (1, 0, 1)
this->tris[11].v3.x = 0; this->tris[11].v3.y = 0; this->tris[11].v3.z = 1; // (0, 0, 1)



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
