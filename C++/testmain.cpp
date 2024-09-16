#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <Eigen>

#include "Mesh.hpp"
#include "Node.hpp"
#include "FEMParameters.hpp"
#include "Solver.hpp"
#include "Mesh.hpp"
#include "Solver.hpp"

using namespace std;


// TP2
int main(){

    // FEMParameters parameters;
    // // if (!parameters.getParameterValue()) {
    // //     std::cerr << "Error : Impossible load the parameters." << std::endl;
    // //     return 1;  // Arrêtez le programme avec un code d'erreur
    // // }

    // Mesh mesh1;
    // std::string namefile  = "square.txt";
    // // bool meshOk = mesh1.loadMeshObj("square.obj");
    // bool meshOk = mesh1.loadMeshGmsh(namefile);
    // if(!meshOk){
    //     cout << "Problem in the mesh " << endl;
    // }
    // // bool meshOk = mesh1.loadMesh("../FicMaillage/d1q1_2");
    // mesh1.printMesh();

    // int nbNodes = mesh1.getNodesNumber();
    // cout << "Number of nodes in the mesh :" << nbNodes << endl;

    // int p = 3;

    // // float ** MatElem = alloctab(p, p);
    // std::vector<std::vector<double>> MatElem(p, std::vector<double>(p, 0.0));
    // std::vector<double> SMbrElem(p, 0.0);
    
    // std::vector<int> NuDElem(p, 0);
    
    
    // std::vector<double> uDElem(p, 0.0);
    // // // std::vector<double> coordEl[p];

    // int typEl = 2;
    // int i= 1;
    // for(auto element : mesh1.getElements()){
    //     for (auto &row : MatElem) {
    //         for (auto &elem : row) {
    //             elem = 0.0;
    //         }
    //     }
    //     SMbrElem.assign(SMbrElem.size(), 0.0);
    //     element.cal1Elem(MatElem, SMbrElem, NuDElem, uDElem);
    //     element.impCalEl(i, typEl, 3, MatElem, SMbrElem,
    //            NuDElem, uDElem);
    //     i++;
    // }


    FEMParameters parameters;
    Mesh mesh;
    // bool meshOk = mesh.loadMeshGmsh(parameters.getMeshName());
    bool meshOk = mesh.loadMsh(parameters.getMeshName());
    if(!meshOk){
        cout << "Problem reading the mesh " << endl;
    }
    // mesh.printMesh();
    Solver solver(mesh, parameters);
    solver.assemble();

    // solver.printB();

    // FEMUtilities::printMat<double>(solver.getA2(), "A2");
    // FEMUtilities::printVec<double>(solver.getb(), "b");

    Eigen::MatrixXd lower = FEMUtilities::mat2Eigen(solver.getA2());
    Eigen::VectorXd b = FEMUtilities::vec2Eigen(solver.getb());

    Eigen::MatrixXd A = lower.selfadjointView<Eigen::Upper>();

    // std::cout << "Matrice Eigen::MatrixXd :\n" << A << std::endl;

    Eigen::VectorXd x = A.fullPivLu().solve(b);    

    // std::cout << "Solution x : \n" << x << std::endl;


    FEMUtilities::saveResults(x, "results/simu1.txt");

    // solver.AFFSMD();



    return 0;
}