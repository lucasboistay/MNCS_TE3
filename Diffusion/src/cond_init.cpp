#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

//en-têtes personnels
#include "../include/cond_init.h"

#include <Eigen/Dense>

using namespace std;
float L;

void init2sinus(Eigen::VectorXf &uold, const float dx){
    
    for (int i=0; i<uold.size(); i++){
        uold(i) = 1 + sin((M_PI*(i+1)*dx)/L) + 0.2*sin((5*M_PI*(i+1)*dx)/L);
    }
}

void marche(Eigen::VectorXf &uold){
    
    for (int i=0; i< uold.size()/2 ; i++){
        uold(i) = 1;
    }
    
    for (int i= uold.size()/2; i< uold.size(); i++){
        uold(i) = -1;
    }
}



