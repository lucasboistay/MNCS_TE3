#include <iostream>
#include <fstream>
#include <iomanip>

//en-t�tes personnels
#include "../include/condlim.h"

#include <Eigen/Dense>

using namespace std;

void condlimites1(Eigen::VectorXf &nord, Eigen::VectorXf &sud, Eigen::VectorXf &ouest, Eigen::VectorXf &est){
float tn = 1.0;
float ts = 2.0;
float tw = 3.0;
float te = 4.0;

//cout<< "donner les valeurs de tn, ts, tw, te"<<endl;
//cin >> tn >> ts >> tw >> te;

nord = Eigen::VectorXf::Constant(nord.size(), tn);
sud = Eigen::VectorXf::Constant(sud.size(), ts);
ouest = Eigen::VectorXf::Constant(ouest.size(), tw);
est = Eigen::VectorXf::Constant(est.size(), te);

}


Eigen::VectorXf second_membre(const Eigen::VectorXf &nord, const Eigen::VectorXf &sud, const Eigen::VectorXf &ouest, const Eigen::VectorXf &est){

int nc = nord.size();
int nl = est.size();

Eigen::VectorXf B(nl*nc);
B = Eigen::VectorXf::Zero(nl*nc);

B.head(nc) = -nord;
B.tail(nc) = -sud;

for (int i=0; i<nl; i++){
    B(i*nc) -= ouest(i);
    B(i*nc + nc -1) -= est(i);
    }
    
    
return B;
}


