#ifndef MATRICES_H
#include <Eigen/Dense>

Eigen::MatrixXf mat_L1D(int nx);
Eigen::MatrixXf mat_id(int nx);
Eigen::MatrixXf matalpha(int nx, const float alpha);

#define MATRICES_H
#endif
