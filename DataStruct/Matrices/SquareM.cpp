#include "Matrix.h"
#include <cstdint>

template <typename T>
SquareM<T>::SquareM(int sizeXY) : Matrix<T>(sizeXY, sizeXY){

}


template <typename T>
SquareM<T>::SquareM(Matrix<T>* m) : Matrix<T>(m) {

}

template class SquareM<int>;
template class SquareM<float>;
template class SquareM<double>;
template class SquareM<char>;
template class SquareM<uint8_t>;
template class SquareM<uint16_t>;
template class SquareM<uint32_t>;
template class SquareM<uint64_t>;
template class SquareM<int8_t>;
template class SquareM<int16_t>;
template class SquareM<int64_t>;

