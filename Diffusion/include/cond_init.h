#ifndef COND_INIT_H
#include <Eigen/Dense>
using namespace std;
void init2sinus(Eigen::VectorXf &uold, const float dx);
void marche(Eigen::VectorXf &uold);
#define COND_INIT_H
#endif
