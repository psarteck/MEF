#ifndef MESH_C
#define MESH_C


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

#include "Element.h"
#include "Node.h"

using namespace std;

class Mesh {

    private : 
        string fileName;
        vector<Node> nodes;
        vector<Edge> edges;
        vector<Element> elements;
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