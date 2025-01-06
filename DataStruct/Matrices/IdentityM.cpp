#include "Matrix.h"
#include <cstdint>

template <typename T>
IdentityM<T>::IdentityM(int sizeXY) :  SquareM<T>(sizeXY){
  for(int  i =0; i <sizeXY;  i++){
    this->set(i, i, 1);
  }
}
template <typename T>
void  IdentityM<T>::set(int dimX, int dimY, T value){
  SquareM<T>::set(dimX, dimY, value);
}
template <typename T>
IdentityM<T>::IdentityM(int sizeXY, T value) :  SquareM<T>(sizeXY){
  for(int  i =0; i <sizeXY;  i++){
    this->set(i, i, value);
  }
}
template <typename T>
IdentityM<T>::IdentityM(int sizeXY, T value, bool flipped) :  SquareM<T>(sizeXY){
  if(flipped){ 
    for(int  i =0; i <sizeXY;  i++){
      this->set((sizeXY-1)-i, i, value);
    }
  }else{
    for(int  i =0; i <sizeXY;  i++){
      this->set(i, i, value);
    }

  }
}

template class IdentityM<int>;
template class IdentityM<float>;
template class IdentityM<double>;
template class IdentityM<char>;
template class IdentityM<uint8_t>;
template class IdentityM<uint16_t>;
template class IdentityM<uint32_t>;
template class IdentityM<uint64_t>;
template class IdentityM<int8_t>;
template class IdentityM<int16_t>;
template class IdentityM<int64_t>;
