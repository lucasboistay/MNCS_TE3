#ifndef UTIL_H
#include <Eigen/Dense>
#include <string>
void ecrit(const Eigen::VectorXf &, const float, const float, const std::string &);
void ecrit_entete(const Eigen::VectorXf &, const float, const float, const float, const float, const std::string &);
#define UTIL_H
#endif
