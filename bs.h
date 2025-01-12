#ifndef RANDOM_H
#define RANDOM_H

#include "DataStruct/Matrices/Matrix.h"
#include "DataStruct/Vector/Vector.h"
#include "Shapes/Vertex/Vertex.h"
namespace bs{
  void VMprod4(Vec4D<float> inputVec, GeneralM<float> matrix, Vec4D<float>* targetVec);
  void mulMatvec(Vec3D<float> input, Vec3D<float> out, GeneralM<float> matrix);
  void mulMatVector(Vertex<float> inputVec, Vertex<float>* targetVec, GeneralM<float>* matrix);
void updateRotMat(GeneralM<float>* matrix, float thetaX, float thetaY, float thetaZ);
void mulMatVectorSIMD();



}
#endif // !RANDOM_H

