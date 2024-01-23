#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "Mesh.h"
#include "Node.h"
#include "FEMParameters.h"

using namespace std;


// TP2
int main(){

    FEMParameters parameters;
    // if (!parameters.getParameterValue()) {
    //     std::cerr << "Error : Impossible load the parameters." << std::endl;
    //     return 1;  // Arrêtez le programme avec un code d'erreur
    // }

    Mesh mesh1;
    std::string namefile  = "square.txt";
    // bool meshOk = mesh1.loadMeshObj("square.obj");
    bool meshOk = mesh1.loadMeshGmsh(namefile);
    if(!meshOk){
        cout << "Problem in the mesh " << endl;
    }
    // bool meshOk = mesh1.loadMesh("../FicMaillage/d1q1_2");

    int nbNodes = mesh1.getNodesNumber();
    cout << "Number of nodes in the mesh :" << nbNodes << endl;

    int p = 3;

    // float ** MatElem = alloctab(p, p);
    std::vector<std::vector<double>> MatElem(p, std::vector<double>(p, 0.0));
    std::vector<double> SMbrElem(p, 0.0);
    
    std::vector<int> NuDElem(p, 0);
    
    
    std::vector<double> uDElem(p, 0.0);
    // // std::vector<double> coordEl[p];

    int typEl = 2;
    int i= 1;
    for(auto element : mesh1.getElements()){
        element.cal1Elem(MatElem, SMbrElem, NuDElem, uDElem);
        element.impCalEl(i, typEl, 3, MatElem, SMbrElem,
               NuDElem, uDElem);
        i++;
    }

    return 0;
}