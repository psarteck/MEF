#include "Eigen"
#include <iostream>

namespace FEMUtilities {
    Eigen::MatrixXd vector2EigenMatrix(const std::vector<std::vector<double> >& vecOfVec); 
}