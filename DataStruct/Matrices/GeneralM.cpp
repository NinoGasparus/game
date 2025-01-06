#include "Matrix.h"
#include <cstdint>

template <typename T>
GeneralM<T>::GeneralM(int sizeXY) : Matrix<T>(sizeXY, sizeXY){
  
}

template <typename T>
GeneralM<T>::GeneralM(int sizeX, int sizeY) : Matrix<T>(sizeX, sizeY){

}




template class GeneralM<int>;
template class GeneralM<float>;
template class GeneralM<double>;
template class GeneralM<char>;
template class GeneralM<uint8_t>;
template class GeneralM<uint16_t>;
template class GeneralM<uint32_t>;
template class GeneralM<uint64_t>;
template class GeneralM<int8_t>;
template class GeneralM<int16_t>;
template class GeneralM<int64_t>;
