#include <cmath>
#include <cstdio>
#include <immintrin.h>
#include <stdexcept>
#include "DataStruct/Matrices/Matrix.h"
#include "DataStruct/Vector/Vector.h"
#include "Shapes/Vertex/Vertex.h"
#include "bs.h"

namespace bs{
void VMprod4(Vec4D<float> inputVec, GeneralM<float> matrix, Vec4D<float>* targetVec) {
    if (matrix.size->x() != 4 || matrix.size->y() != 4) {
        throw std::invalid_argument("Matrix must be 4x4 for VMprod4.");
    }

    targetVec->x() = inputVec.x() * matrix.get(0, 0) +
                     inputVec.y() * matrix.get(0, 1) +
                     inputVec.z() * matrix.get(0, 2) +
                     inputVec.w() * matrix.get(0, 3);

    targetVec->y() = inputVec.x() * matrix.get(1, 0) +
                     inputVec.y() * matrix.get(1, 1) +
                     inputVec.z() * matrix.get(1, 2) +
                     inputVec.w() * matrix.get(1, 3);

    targetVec->z() = inputVec.x() * matrix.get(2, 0) +
                     inputVec.y() * matrix.get(2, 1) +
                     inputVec.z() * matrix.get(2, 2) +
                     inputVec.w() * matrix.get(2, 3);

    targetVec->w() = inputVec.x() * matrix.get(3, 0) +
                     inputVec.y() * matrix.get(3, 1) +
                     inputVec.z() * matrix.get(3, 2) +
                     inputVec.w() * matrix.get(3, 3);
  }




void mulMatVector(Vertex<float> inputVec, Vertex<float>* targetVec, GeneralM<float>* matrix){
targetVec->x = inputVec.x * matrix->get(0, 0) +
               inputVec.y * matrix->get(0, 1) +
               inputVec.z * matrix->get(0, 2) +
               1 * matrix->get(0, 3);

targetVec->y = inputVec.x * matrix->get(1, 0) +
               inputVec.y * matrix->get(1, 1) +
               inputVec.z * matrix->get(1, 2) +
               1 * matrix->get(1, 3);

targetVec->z = inputVec.x * matrix->get(2, 0) +
               inputVec.y * matrix->get(2, 1) +
               inputVec.z * matrix->get(2, 2) +
               1 * matrix->get(2, 3);

float w = inputVec.x * matrix->get(3, 0) +
          inputVec.y * matrix->get(3, 1) +
          inputVec.z * matrix->get(3, 2) +
          1 * matrix->get(3, 3);

if(w != 0) {
    targetVec->x /= w;
    targetVec->y /= w;
    targetVec->z /= w;
}

}
void mulMatVectorSIMD(){
 /*alignas(32) float arr1[] = {1,2,3,4,5,6,7,8};
  alignas(32)float arr2[] = {8,7,6,5,4,3,2,1};
__m256  m_1 = _mm256_set1_ps(1);

__m256    m_2 = _mm256_set1_ps(1);
  m_1= _mm256_load_ps(arr1);
  m_2 = _mm256_load_ps(arr2);
__m256  m_3 = _mm256_add_ps(m_1, m_2);


alignas(32)float vars[8];
  printf("%f %f %f %f %f %f %f %f", vars[0], vars[1], vars[2], vars[3], vars[4], vars[5], vars[6], vars[7]);
/*
TX = IX * m00 + IY * m01 + IZ * m02 + m03
TY = IX * m10 + IY * m11 + IZ * m12 + m12
TZ = IX * m20 + IY * m21 + IZ * m22 + m23
 */ 
}

/*
void updateRotMat(GeneralM<float>* matrix, float thetaX, float thetaY, float thetaZ) {
    float cosZ = cos(thetaZ), sinZ = sin(thetaZ);

    // Z-axis rotation matrix
    float rot[3][3] = {
        {cosZ, -sinZ, 0},  // First row: [cosZ, -sinZ, 0]
        {sinZ,  cosZ, 0},  // Second row: [sinZ, cosZ, 0]
        {0,     0,    1}   // Third row: [0, 0, 1] (no change to Z-coordinate)
    };

    // Set the values in the matrix
    matrix->set(0, 0, rot[0][0]); matrix->set(0, 1, rot[0][1]); matrix->set(0, 2, rot[0][2]);
    matrix->set(1, 0, rot[1][0]); matrix->set(1, 1, rot[1][1]); matrix->set(1, 2, rot[1][2]);
    matrix->set(2, 0, rot[2][0]); matrix->set(2, 1, rot[2][1]); matrix->set(2, 2, rot[2][2]);
}*/


void updateRotMat(GeneralM<float>* matrix, float thetaX, float thetaY, float thetaZ) {
    float cosX = cos(thetaX), sinX = sin(thetaX);
    float cosY = cos(thetaY), sinY = sin(thetaY);
    float cosZ = cos(thetaZ), sinZ = sin(thetaZ);

    // [1,    0,     0    ]
    // [0, cosX, -sinX    ]
    // [0, sinX,  cosX    ]

    // [ cosY, 0, sinY    ]
    // [   0,  1,    0    ]
    // [-sinY, 0, cosY    ]

    // [cosZ, -sinZ, 0    ]
    // [sinZ,  cosZ, 0    ]
    // [  0,     0,  1    ]

    float rot[3][3] = {
        {cosY * cosZ, -cosY * sinZ, sinY},
        {sinX * sinY * cosZ + cosX * sinZ, -sinX * sinY * sinZ + cosX * cosZ, -sinX * cosY},
        {-cosX * sinY * cosZ + sinX * sinZ, cosX * sinY * sinZ + sinX * cosZ, cosX * cosY}
    };

    matrix->set(0, 0, rot[0][0]); matrix->set(0, 1, rot[0][1]); matrix->set(0, 2, rot[0][2]);
    matrix->set(1, 0, rot[1][0]); matrix->set(1, 1, rot[1][1]); matrix->set(1, 2, rot[1][2]);
    matrix->set(2, 0, rot[2][0]); matrix->set(2, 1, rot[2][1]); matrix->set(2, 2, rot[2][2]);
}
}

