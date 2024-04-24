#include "../include/methodes.h"

Eigen::VectorXf avance_expl(Eigen::VectorXf uold, const float alpha, const int nx, const float ug0, const float ud0){

    Eigen::VectorXf unew(nx);
    unew(0) = alpha*ug0 + (1-2*alpha)*uold(0) + alpha*uold(1);
    for (int j=1; j<nx-1; j++){
        unew(j) = alpha*uold(j-1) + (1-2*alpha)*uold(j) + alpha*uold(j+1);
    }
    unew(nx-1) = alpha*uold(nx-2) + (1-2*alpha)*uold(nx-1) + alpha*ud0;
    return unew;
    
    
}

Eigen::VectorXf avance_impl(Eigen::VectorXf uold, Eigen::VectorXf V, Eigen::MatrixXf IM, const float alpha, const int nx){

    Eigen::VectorXf unew(nx);
    
    unew = IM*(uold + alpha*V);

    return unew;
    
    
}

Eigen::VectorXf avance_cranknic(Eigen::VectorXf uold, Eigen::VectorXf V, Eigen::MatrixXf IM, const float alpha, const int nx){

    Eigen::VectorXf unew(nx);
    
    unew = IM*(IM*uold + (alpha/2)*(V + V));

    return unew;
    
    
}
