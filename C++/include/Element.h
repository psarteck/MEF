#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <string>
#include "Edge.h"
#include "Node.h"
#include <iostream>
// #include "FEMUtilities.h"



class Element {

    private : 
        const int id;   
        const std::vector<int> nodeIds;
        std::vector<Edge> edges;
        std::vector<Node> nodes;
        std::vector<double> valBase;
        std::vector<std::vector<double> > valDerBase;
        std::string type;
        int label;
        int dimension;
    public :
        // Element(int id_, const std::vector<int>& nodeIds_);

        Element(int id_, std::vector<int>& nodeIds, std::vector<Node>& nodes_);

        void baseFunctions(const Node& pts);
        void baseDerFunctions(const Node& pts);
        std::vector<double> transFK(std::vector<Node> selectNodes);
        std::vector<std::vector<double> > matJacob(std::vector<Node> selectNodes);
        std::vector<std::vector<double> > invert2x2(std::vector<std::vector<double> >& mat, double& det);

        const int getId() const;

        const std::vector<int>& getNodeIDs() const;

        Node getNodeById(int nodeId) const;

};

#endif