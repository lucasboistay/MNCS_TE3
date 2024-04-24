#include <iostream>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>
#include <cmath>
#include <string>
#include <functional>
#include <chrono>

//en-t�tes personnels

#include "../include/matrices.h"
#include "../include/io.h"
#include "../include/condlim.h"

using namespace std::chrono;


int main(){

int nl =100;
int nc=100;
float dx = 4.0;
float dy = 5.0;
float p = dx/(nl+1);
cout<<p<<endl;

Eigen::VectorXf nord(nc);
Eigen::VectorXf sud(nc);
Eigen::VectorXf ouest(nl);
Eigen::VectorXf est(nl);
Eigen::VectorXf temp(nl*nc);


condlimites1(nord, sud, ouest, est);
Eigen::VectorXf sm;
sm = second_membre(nord, sud, ouest, est);


Eigen::MatrixXf m;
m = matl2d(nl, nc);

string filename = "data/lp.dat";

auto start = std::chrono::high_resolution_clock::now();
temp = m.colPivHouseholderQr().solve(sm);
//m.ldlt().solve(sm);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop-start);
cout << duration.count() << " ms" << endl;
ecritemp(filename, temp, nord, sud, ouest, est, p);
return 0;

}
