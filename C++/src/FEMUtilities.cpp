#include "FEMUtilities.h"

namespace FEMUtilities {
    Eigen::MatrixXd vector2EigenMatrix(const std::vector<std::vector<double> >& vecOfVec) {
        if (vecOfVec.empty() || vecOfVec[0].empty()) {
            std::cerr << "Error : Vector of vectors is empty." << std::endl;
            return Eigen::MatrixXd();
        }

        int rows = static_cast<int>(vecOfVec.size());
        int cols = static_cast<int>(vecOfVec[0].size());

        for (const auto& row : vecOfVec) {
            if (static_cast<int>(row.size()) != cols) {
                std::cerr << "Error : Vector is irregular." << std::endl;
                return Eigen::MatrixXd();
            }
        }

        Eigen::Map<const Eigen::MatrixXd> eigenMap(vecOfVec[0].data(), rows, cols);

        // Copier la matrice pour garantir une copie indépendante
        return eigenMap;
    }
}