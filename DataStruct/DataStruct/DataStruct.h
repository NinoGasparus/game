#ifndef DATASTRUCT_H
#define DATASTRUCT_H 

#include <type_traits>
template <typename T>
class DataStruct{
public:
    T* data = nullptr;
    int size = 0;
 
    DataStruct(int size ){
      static_assert(std::is_arithmetic<T>::value, "Cant be non numeric" );
      data = new T[size];
      this->size  = size;
    }
    virtual ~DataStruct(){
      delete[] data;
    }
};
#endif
