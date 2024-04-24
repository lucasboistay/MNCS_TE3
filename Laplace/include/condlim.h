#ifndef CONDLIM_H
#include <Eigen/Dense>
using namespace std;
void condlimites1(Eigen::VectorXf &nord, Eigen::VectorXf &sud, Eigen::VectorXf &ouest, Eigen::VectorXf &est);
Eigen::VectorXf second_membre(const Eigen::VectorXf &nord, const Eigen::VectorXf &sud, const Eigen::VectorXf &ouest, const Eigen::VectorXf &est);
#define CONDLIM_H
#endif
