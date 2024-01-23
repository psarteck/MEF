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
        int nodesNumber;
        int edgeNumber;
        int elementNumber;
    public :
        Mesh();

        bool loadMeshObj(const std::string& fileName);

        bool loadMeshGmsh(const std::string& fileName);

        void printMesh() const;

        void integrate();

        Node& getNodeAt(int position);

        std::vector<Node> getNodes();
        std::vector<Element> getElements();
        // std::vector<Node> getNodes();

        Edge& getEdge(int position);
        int getDimension();
        int getNodesNumber();
        int getTrianglesNumber();
        int getEdgesNumber();


        std::unordered_set<int> getBoundaryNodes() const;

};

#endif