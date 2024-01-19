#ifndef FEM_PARAMETERS_H
#define FEM_PARAMETERS_H

#include "Mesh.h"
#include <string>

class FEMParameters{
private:
    std::string mesh;
    std::string lagrange;
    std::string quadrature;
    std::string parameterFile;

public:
    FEMParameters();

    bool getParameterValue();

    const std::string& getMesh() const;
    const std::string& getLagrange() const;
    const std::string& getQuadrature() const;
};




#endif