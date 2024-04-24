#include "../include/matrices.h"
#include <iostream>

using namespace Eigen;
using namespace std;

MatrixXf mat_id(int n){
    return MatrixXf::Identity(n, n);
}

MatrixXf mat_diag(int n){
    MatrixXf mat = mat_id(n);
    mat = -4*mat;
    
    for (int i=1; i<n; i++){
        mat(i, i-1) = 1;
        mat(i-1, i) = 1;
    }

return mat;
}

MatrixXf matl2d(int nl, int nc){

MatrixXf mat2 = MatrixXf::Zero(nl*nc, nl*nc);
//cout << mat2;

for (int i=0; i<nl; i++){
    mat2.block(i*nc, i*nc, nc, nc) = mat_diag(nc);
    }
    
for (int i=0; i<nl-1; i++){

    mat2.block(i*nc, (i+1)*nc, nc, nc) = mat_id(nc);
    mat2.block((i+1)*nc, i*nc, nc, nc) = mat_id(nc);
    }
    
return mat2;

}

