#include "FEMParameters.h"

FEMParameters::FEMParameters() : parameterFile("parameters.txt"){}

bool FEMParameters::getParameterValue() {
    std::ifstream file(parameterFile);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << parameterFile << std::endl;
        return false;
    }

    std::cout << "------ Loading parameters ------" << std::endl; 
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            if (key == "mesh") {
                mesh = value;
            } else if (key == "lagrange") {
                lagrange = value;
            } else if (key == "quadrature") {
                quadrature = value;
            }
        }
    }

    file.close();

    std::cout << "Parameters values : \nMesh : " << mesh << "\nLagrange method : " << lagrange << "\nQuadrature method : " << quadrature << std::endl;
    std::cout << "---------------------------------" << std::endl;
    return true;
}

const std::string& FEMParameters::getMesh() const {
    return mesh;
}

const std::string& FEMParameters::getLagrange() const {
    return lagrange;
}

const std::string& FEMParameters::getQuadrature() const {
    return quadrature;
}

