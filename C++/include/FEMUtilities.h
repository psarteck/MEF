/*---------------------------------------------------------------------------*\

 ██████╗ ██╗  ██╗██╗   ██╗     ███████╗███╗   ███╗
██╔═══██╗╚██╗██╔╝╚██╗ ██╔╝     ██╔════╝████╗ ████║
██║   ██║ ╚███╔╝  ╚████╔╝█████╗█████╗  ██╔████╔██║
██║   ██║ ██╔██╗   ╚██╔╝ ╚════╝██╔══╝  ██║╚██╔╝██║
╚██████╔╝██╔╝ ██╗   ██║        ██║     ██║ ╚═╝ ██║
 ╚═════╝ ╚═╝  ╚═╝   ╚═╝        ╚═╝     ╚═╝     ╚═╝
 * 
 * Copyright (C) 2024 by Matthieu PETIT
\*---------------------------------------------------------------------------*/
#include "Eigen"
#include <iostream>

using namespace std;

namespace FEMUtilities {

    Eigen::MatrixXd mat2Eigen(const std::vector<std::vector<double> >& vecOfVec); 

    Eigen::VectorXd vec2Eigen(const std::vector<double>& vec);

    template <typename T>
    void printMat(std::vector<std::vector<T> > mat, std::string name);

    template <typename T>
    void printVec(std::vector<T> vec, std::string name);

    // std::vector<double> node2double(std::vector<Node> vec);

}






