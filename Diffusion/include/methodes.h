#ifndef METHODES_H
#include <Eigen/Dense>
Eigen::VectorXf avance_expl(Eigen::VectorXf , const float, const int, const float, const float);
Eigen::VectorXf avance_impl(Eigen::VectorXf, Eigen::VectorXf, Eigen::MatrixXf, const float, const int);
Eigen::VectorXf avance_cranknic(Eigen::VectorXf, Eigen::VectorXf, Eigen::MatrixXf, const float, const int);
#define METHODES_H
#endif
