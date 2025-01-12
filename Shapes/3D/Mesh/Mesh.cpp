#include "Mesh.h"
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

template <typename T>
Mesh<T>::Mesh(){

}
template <typename T>
Mesh<T>::Mesh(int64_t triCount){
  this->tris = new Triangle<T>[triCount];
}

template <typename T>
Mesh<T>::~Mesh(){
  delete[] this->tris;
}



void getVertex(std::string line, float* target){
 //format v -1.0000000 1.000000 0.000000
std::string  values[3];
int indexer = -1;
int counter = 0; //start at -1 so firsts space sets it  to 0
char x = 'v';
  while(x != '\0'){
    x = line[counter];
    if(x == 'v'){

    }else 
    if(x == ' '){
      indexer++;
    }else
    if(x == '-'){
      values[indexer] +=x ;

    }else
    if(x == '.'){

      values[indexer] +=x;
    }else
    if(x >= 48 && x <=  57){
      values[indexer] +=x;

    }else
    if(x == '\0' || x == '\n' || x == '\t'){
      goto end;
    }else{
      std::cerr << "VertexGen: unknown char '" << std::bitset<8>(x) << "' found reading file\n";
    }
      counter++;
  }
end:
target[0] = std::stof(values[0]);
target[1] = std::stof(values[1]);
target[2] = std::stof(values[2]);
}

void  getTri(std::string line, int* target){
 //format f 1 2 3
std::string  values[3];
int indexer = -1;
int counter = 0; //start at -1 so firsts space sets it  to 0
char x = 'v';
  while(x != '\0'){
    x = line[counter];
    if(x == 'f'){

    }else 
    if(x == ' '){
      indexer++;
    }else 
    if(x == '-'){
      values[indexer] +=x;
    }else
    if(x == '.'){
      values[indexer] +=x;
    }else
    if(x >= 48 && x <=  57){
      values[indexer] +=x;
    }else 
    if(x == '\0' || x== '\n' || x == '\t'){
      goto end;
    }else{
      std::cerr << "TriangleGen: unknown char '" << x << "' found reading file\n";
    }
      counter++;
  }
end:
target[0] = std::stoi(values[0]);
target[1] = std::stoi(values[1]);
target[2] = std::stoi(values[2]);
}


template <typename T>
void  Mesh<T>::loadOBJ(std::string filename){
  std::ifstream file(filename);
    if(!file.is_open()){
      std::cerr << "failed to open " << filename << "\n";  
    }else{
      std::string line;
      
      while(getline(file, line)){
        switch(line[0]){
          case '#': break;
          case 'o': break;
          case 'v': vertexCount++;  break;
          case 's': break;
          case 'f': triangleCount++; break;
        } //todo multiple object handling
      }
      file.clear(); //re read file
      file.seekg(0);
      
      
      float meshData[vertexCount][3];
      int   indices[triangleCount][3];

      int counter = 0;
      this->tris = new Triangle<T>[triangleCount];
      while(getline(file, line)){
        switch(line[0]){
          case '#': break;
          case 'o': break;
          case 'v': getVertex(line, meshData[counter]); counter++ ;break;
          case 's': counter =  0; break;
          case 'f': getTri(line, indices[counter]);counter++; break;
        } //todo multiple object handling
      }
      float minX =0;
      float minY =0;
      float minZ =0;
      for(int i =0; i < vertexCount; i++){
        minX = std::min(minX, meshData[i][0]);
        minY = std::min(minY, meshData[i][1]);
        minZ = std::min(minZ, meshData[i][2]);
      }
      minX = minX < 0 ? -minX : 0;
      minY = minY < 0 ? -minY : 0;
      minZ = minZ < 0 ? -minZ : 0;
      for(int i =0; i < vertexCount; i++){
        meshData[i][0] += minX;
        meshData[i][1] += minY;
        meshData[i][2] += minZ;
      }
      for (int i = 0; i < triangleCount; i++) {
        this->tris[i].v1.write(meshData[indices[i][0]][0],meshData[indices[i][0]][1],meshData[indices[i][0]][2]);
        this->tris[i].v2.write(meshData[indices[i][1]][0],meshData[indices[i][1]][1],meshData[indices[i][1]][2]);
        this->tris[i].v3.write(meshData[indices[i][2]][0],meshData[indices[i][2]][1],meshData[indices[i][2]][2]);
      }
    printf("vertexpoolDump\n");
      for(int i   =0; i< vertexCount; i++){
        printf("%f %f %f\n", meshData[i][0], meshData[i][1], meshData[i][2]);
      }
      printf("triDump\n");
      for(int  i =0; i<triangleCount; i++){
        printf("%i %i %i \n", indices[i][0], indices[i][1], indices[i][2]);
    }
    }


}


template <typename T>
void Mesh<T>::reScale(){
for(int i = 0; i < triangleCount; i++){
    this->tris[i].scale(this->scaleX, this->scaleY, this->scaleZ);
  }
}
template class Mesh<int>;
template class Mesh<float>;
template class Mesh<double>;
template class Mesh<char>;
template class Mesh<uint8_t>;
template class Mesh<uint16_t>;
template class Mesh<uint32_t>;
template class Mesh<uint64_t>;
template class Mesh<int8_t>;
template class Mesh<int16_t>;
template class Mesh<int64_t>;
