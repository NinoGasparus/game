#ifndef DATASTRUCT_H
#define DATASTRUCT_H 

class DataStruct{
public:
    float* data = nullptr;
    int size = 0;
 
    DataStruct(int size){
      data = new float[size];
      this->size  = size;
    }
    virtual ~DataStruct(){
      delete[] data;
    }
};
#endif
