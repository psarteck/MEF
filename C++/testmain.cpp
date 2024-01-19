#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "Mesh.h"
#include "Node.h"
#include "FEMParameters.h"

using namespace std;

int main(){

    FEMParameters parameters;
    if (!parameters.getParameterValue()) {
        std::cerr << "Error : Impossible load the parameters." << std::endl;
        return 1;  // Arrêtez le programme avec un code d'erreur
    }

    Mesh mesh1;
    std::string namefile  = "square.txt";
    // bool meshOk = mesh1.loadMeshObj("square.obj");
    bool meshOk = mesh1.loadMeshGmsh("square.txt");
    // bool meshOk = mesh1.loadMesh("../FicMaillage/d1q1_2");

    Node noeud(2.3,23.3,54.3, 12);

    mesh1.printMesh();

    // cout << mesh1.getNode(0).getX() << endl;
    return 0;
}