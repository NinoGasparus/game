#include "Matrix.h"
#include <cstdint>
#include <iostream>


template <typename T>
Matrix<T>::Matrix(){
  this->size = new Vec2D<int>();

}
template <typename T>
Matrix<T>::Matrix(int sizeX, int sizeY) : Matrix(){
  this->size->x() = sizeX;
  this->size->y()= sizeY;
  this->data = new T*[sizeY];
  for(int i =0; i < sizeY; i++){
    data[i] = new T[sizeX];
  }
}

template <typename T>
Matrix<T>::Matrix(Matrix* m) : Matrix(){
  int sizeX = m->size->x();
  int sizeY = m->size->y();

  this->size->x() = sizeX;
  this->size->y()= sizeY;
  this->data = new T*[sizeY];
  for(int i =0; i < sizeY; i++){
    data[i] = new T[sizeX];
  }
  for(int i =0; i < sizeY; i++){
    for(int j =0; j < sizeX; j++){
      data[i][j] = m->data[i][j];
    }
  }

}

template <typename T>
void Matrix<T>::set(int dimX, int dimY, T value){
  this->data[dimY][dimX] = value;
}


template <typename T>
void Matrix<T>::set(Matrix<T> matrix){
  if(this->size->x() != matrix.size->x() || this->size->y() != matrix.size->y()){
    for(int i =0; i < this->size->y(); i++){
      delete[] data[i];
    }
    delete [] data;
    this->size->x() = matrix.size->x();
    this->size->y() = matrix.size->y();
    this->data = new T*[this->size->y()];
    for(int i =0; i <this->size->y(); i++){
      data[i] = new T[this->size->x()];
    }
  }
  
  for(int i =0; i < this->size->y(); i++){
    for(int j=0;  j < this->size->x(); j++){
      this->data[i][j] = matrix.data[i][j];
    }
  }
}

template <typename T>
T Matrix<T>::get(int dimX, int dimY){
  return this->data[dimY][dimX];
}






template <typename T>
Matrix<T>::~Matrix(){
  for(int i =0; i < this->size->y(); i++){
    delete[] data[i];
  }
  delete [] data;
}
template <typename T>
void Matrix<T>::print(){
  printf("Matrix [x: %i, y: %i]\n", this->size->x(), this->size->y());
  for(int i =0; i < this->size->y();  i++){
    printf("| ");
    for(int j = 0; j < this->size->x(); j++){
      std::cout << this->data[i][j] << " ";
    }
    printf("|\n");
  }
}






template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<char>;
template class Matrix<uint8_t>;
template class Matrix<uint16_t>;
template class Matrix<uint32_t>;
template class Matrix<uint64_t>;
template class Matrix<int8_t>;
template class Matrix<int16_t>;
template class Matrix<int64_t>;
