#include "../include/matrices.h"
#include <iostream>

using namespace Eigen;
using namespace std;

MatrixXf mat_id(int nx){
    return MatrixXf::Identity(nx, nx);
}

MatrixXf mat_L1D(int nx){
    MatrixXf mat = mat_id(nx);
    mat = -2*mat;
    
    for (int i=1; i<nx; i++){
        mat(i, i-1) = 1;
        mat(i-1, i) = 1;
    }

return mat;
}

MatrixXf matalpha(int nx, const float alpha){
    MatrixXf L1D(nx, nx);
    MatrixXf Identite(nx, nx);
    MatrixXf M(nx, nx);
    
    Identite = mat_id(nx);
    L1D = mat_L1D(nx);
    M = Identite - alpha*L1D;
    
    return M;
    

}

