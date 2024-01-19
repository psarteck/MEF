#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main() {

    int dimension;
    int nbVertices;
    int nbEdges;

    // Ouvrir le fichier en lecture
    std::ifstream file("square.gmsh");

    // Vérifier si le fichier est ouvert correctement
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    // Lire les lignes du fichier jusqu'à ce que la ligne commence par "Dimension"
    std::string ligne;
    while (std::getline(file, ligne) && ligne.find("Dimension") != 0) {}
    file >> dimension ;
    cout << dimension << endl;
    while (std::getline(file, ligne) && ligne.find("Vertices") != 0) {}
    file >> nbVertices ;
    cout << nbVertices << endl;

    std::vector<std::vector<double>> vertices;

    vertices.resize(nbVertices, std::vector<double>(3, 0.0));

    for(int i = 0 ; i < nbVertices ; i++){
        file >> vertices[i][0] >> vertices[i][1] >> vertices[i][2];
    }

    for(int i = 0 ; i < nbVertices ; i++){
        cout << vertices[i][0]  << " "<<  vertices[i][1] << " "<< vertices[i][2] << endl;
    }

    while (std::getline(file, ligne) && ligne.find("Edges") != 0) {}
    file >> nbEdges;
    cout << nbEdges << endl;
    std::vector<std::vector<double>> edges;
    edges.resize(nbEdges, std::vector<double>(3, 0.0));

    for(int i = 0 ; i < nbEdges ; i++){
        file >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    for(int i = 0 ; i < nbVertices ; i++){
        cout << edges[i][0]  << " "<<  edges[i][1] << " "<< edges[i][2] << endl;
    }



    // Fermer le fichier
    file.close();

    return 0;
}
