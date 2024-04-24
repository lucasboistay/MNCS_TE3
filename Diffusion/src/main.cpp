#include <iostream>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>
#include <cmath>
#include <string>
#include <functional>
#include <chrono>

//en-têtes personnels

#include "../include/matrices.h"
#include "../include/util.h"
#include "../include/cond_init.h"
#include "../include/methodes.h"

using namespace std::chrono;


extern float L;

int main(){

string filename = "cranknic.dat";
float dt=2;
int nt = 1000;
float D = 0.01;
float dx = 0.1;
L = 12.0;
int nx = int((L/dx) - 1);
cout << nx <<endl;

float alpha = (D*dt)/(dx*dx);


cout<< "alpha :"<< " " << alpha << " " << "dx :" << " " << dx << endl;


float ug0 = 1.f; //conditions limites
float ud0 = 1.f;

int n = nt + 1;

Eigen::VectorXf unew(nx);
Eigen::VectorXf uold(nx);
Eigen::VectorXf u0_old(nx);


//marche(uold);
init2sinus(uold, dx); //initialisation de uold
ecrit_entete(uold,nt, dx, dt, alpha, filename);

/*
for (int i=0; i<n; i++){
    unew = avance_expl(uold, alpha, nx, ug0, ud0);
    uold = unew;
    ecrit(uold, ug0, ud0, filename);
}

*/

//partie implicite

/*
Eigen::MatrixXf malpha(nx, nx);
Eigen::MatrixXf invmalpha(nx, nx);
Eigen::VectorXf V(nx);
V = Eigen::VectorXf::Zero(nx);

V(0) = ug0;
V(nx-1) = ud0;

malpha = matalpha(nx, alpha);
invmalpha = malpha.inverse();


for (int i=0; i<n; i++){
    unew = avance_impl(uold, V, invmalpha, alpha, nx);
    uold = unew;
    ecrit(uold, ug0, ud0, filename);
}
*/

//partie crank nicolson

Eigen::MatrixXf malpha(nx, nx);
Eigen::MatrixXf invmalpha(nx, nx);
Eigen::VectorXf V(nx);
V = Eigen::VectorXf::Zero(nx);

V(0) = ug0;
V(nx-1) = ud0;

malpha = matalpha(nx, alpha/2);
invmalpha = malpha.inverse();

Eigen::VectorXf u(nx);

for (int i=0; i<n; i++){
    unew = avance_cranknic(uold, V, invmalpha, alpha, nx);
    uold = unew;
    ecrit(uold, ug0, ud0, filename);
}

return 0;

}
