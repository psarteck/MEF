#include "Mesh.h"

using namespace std;

Mesh::Mesh(){}


Node& Mesh::getNodeAt(int position){
    return nodes.at(position);
}

std::vector<Node> Mesh::getNodes(){
    return nodes;
}
std::vector<Element> Mesh::getElements(){
    return elements;
}

Edge& Mesh::getEdge(int position){
    return edges.at(position);
}

int Mesh::getDimension(){
    return dimension;
}
int Mesh::getNodesNumber(){
    return nodesNumber;
}
int Mesh::getTrianglesNumber(){
    return elementNumber;
}
int Mesh::getEdgesNumber(){
    return edgeNumber;
}

void Mesh::printMesh() const{
    std::cout << "Nodes:" << std::endl;
    std::cout << nodes.size() << std::endl;
    std::cout << "Element:" << std::endl;
    std::cout << elements.size() << std::endl;


    for (const auto& node : nodes) {
        std::cout << "Node ID: " << node.getId() << "  X: " << node.getX() << "  Y: " << node.getY() << "  Z: " << node.getZ() << std::endl;
    }

    std::cout << "\nElements:" << std::endl;
    for (const auto& element : elements) {
        std::cout << "Element ID: " << element.getId() << "  Node IDs: ";
        for (int nodeID : element.getNodeIDs()) {
            std::cout << nodeID << " ";
        }
        std::cout << std::endl;
    }
}

// Function to parse a line into a vector of doubles
std::vector<double> parseLine(const std::string& line) {
    std::vector<double> result;
    std::istringstream iss(line);
    double value;
    while (iss >> value) {
        result.push_back(value);
    }
    return result;
}

std::unordered_set<int> Mesh::getBoundaryNodes() const {
    std::unordered_set<int> boundaryNodes;

    // Count the number of times each node appears
    std::unordered_map<int, int> nodeCount;
    for (const auto& element : elements) {
        for (int nodeID : element.getNodeIDs()) {
            auto result = nodeCount.emplace(nodeID, 1);
            if (!result.second) {
                // The node already exists, increment the counter
                result.first->second++;
            }
        }
    }

    // Identify knots on edges
    for (const auto& element : elements) {
        for (int nodeID : element.getNodeIDs()) {
            if (nodeCount.at(nodeID) == 1) {
                // This node is used by a single element, so it's on the edge
                boundaryNodes.insert(nodeID);
            }
        }
    }

    return boundaryNodes;
}


bool Mesh::loadMeshGmsh(const std::string& fileName){

    int nbVertices;
    int nbEdges;
    int nbTriangles;

    // Ouvrir le fichier en lecture
    std::ifstream file(fileName);

    // Vérifier si le fichier est ouvert correctement
    if (!file.is_open()) {
        std::cerr << "Error : impossible to open the file : "<< fileName << std::endl;
        return 1;
    }

    // Lire les lignes du fichier jusqu'à ce que la ligne commence par "Dimension"
    std::string line;
    while (std::getline(file, line) && line.find("Dimension") != 0) {}
    file >> dimension ;
    while (std::getline(file, line) && line.find("Vertices") != 0) {}
    file >> nbVertices ;

    for(int i = 0 ; i < nbVertices ; i++){
        double x, y, z;
        file >> x >> y >> z;
        Node newNode(x,y,z,i+1);
        nodes.push_back(newNode);
    }


    while (std::getline(file, line) && line.find("Edges") != 0) {}
    file >> nbEdges;
    
    for(int i = 0 ; i < nbEdges ; i++){
        int x, y, label;
        file >> x >> y >> label;
        Edge newEdge(getNodeAt(x-1), getNodeAt(y-1), label);
        edges.push_back(newEdge);
    }

    while (std::getline(file, line) && line.find("Triangles") != 0) {}

    file >> nbTriangles;
    cout<< "nbrt : "<<nbTriangles<<endl;
    for(int i = 0 ; i < nbTriangles ; i++){
        int x, y, z, label;
        file >> x >> y >> z >> label;
        std::vector<int> nodeIdList = {x,y,z};
        std::vector<Node> nodeList = {getNodeAt(x-1),getNodeAt(y-1),getNodeAt(z-1)};
        Element newEdge(i+1, nodeIdList, nodeList);
        elements.push_back(newEdge);
    }



    // Fermer le fichier
    file.close();

    nodesNumber = nbVertices;
    edgeNumber = nbEdges;
    elementNumber = nbTriangles;

    return true;

}


void Mesh::integrate(){
    
    // for(auto& element : elements){
    //     element.cal1Elem();
    // }
}





// A REFAIRE : 

// bool Mesh::loadMeshObj(const std::string& fileName) {
//     std::ifstream file(fileName);

//     if (!file.is_open()) {
//         std::cerr << "Erreur : Impossible d'ouvrir le fichier " << fileName << std::endl;
//         return false;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         std::istringstream iss(line);
//         std::string token;
//         iss >> token;

//         if (token == "v") {
//             // Lire les coordonnées d'un nœud
//             double x, y, z;
//             iss >> x >> y >> z;
//             nodes.push_back(Node(x, y, z, nodes.size() + 1));
//         } else if (token == "f") {
//             // Lire les indices de nœuds d'un élément
//             std::vector<int> nodeIndices;
//             int index;
//             while (iss >> index) {
//                 nodeIndices.push_back(index);
//             }

//             // Créer un élément avec les indices lus
//             elements.push_back(Element(elements.size() + 1, nodeIndices, nodes));
//         }
//     }

//     file.close();
//     return true;
// }