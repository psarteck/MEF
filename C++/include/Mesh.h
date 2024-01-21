#ifndef MESH_C
#define MESH_C


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

#include "Node.h"
#include "Element.h"


// using MatrixD = std::vector<std::vector<double> >;
// using VectorD = std::vector<double> ;
// using VectorI = std::vector<double> ;
// using VectorNo = std::vector<Node> ;
// using VectorEd = std::vector<Edge> ;
// using VectorEl = std::vector<Element> ;

class Mesh {

    private : 
        std::string fileName;
        std::vector<Node> nodes;
        std::vector<Edge> edges;
        std::vector<Element> elements;
        int dimension;
    public :
        Mesh();

        bool loadMeshObj(const std::string& fileName);

        bool loadMeshGmsh(const std::string& fileName);

        void printMesh() const;

        Node& getNode(int position);
        Edge& getEdge(int position);

        std::unordered_set<int> getBoundaryNodes() const;

};

#endif