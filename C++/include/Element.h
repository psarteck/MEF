#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <string>
#include "Edge.h"
#include "Node.h"
#include <iostream>
#include <FEMProblem.h>
#include "Quadrature.h"




class Element {

    using MatrixD = std::vector<std::vector<double> >;
    using VectorD = std::vector<double>;
    using VectorI = std::vector<int>;
    using VectorNo = std::vector<Node>;
    using VectorEd = std::vector<Edge>;

    private : 
        const int id;   
        const std::vector<int> nodeIds;
        std::vector<Edge> edges;
        std::vector<Node> nodes;
        std::vector<double> valBase;
        MatrixD valDerBase;
        MatrixD elemMatrix;
        std::vector<double> fElem;

        Quadrature quadraMethodS1;
        // Quadrature quadraMethodT1;
        // Quadrature quadraMethodQ1;

        std::string type;
        int label;
        int dimension;
    public :
        // Element(int id_, const std::vector<int>& nodeIds_);

        Element(int id_, std::vector<int>& nodeIds, std::vector<Node> & nodes_);

        void baseFunctions(const Node& pts);
        void baseDerFunctions(const Node& pts);
        std::vector<double> transFK(std::vector<Node> selectNodes);
        std::vector<std::vector<double> > matJacob(std::vector<Node> selectNodes);
        std::vector<std::vector<double> > invert2x2(std::vector<std::vector<double> >& mat, double& det);
        void ADWDW(double diffElement, std::vector<double> point, std::vector<std::vector<double> > cofvar, std::vector<std::vector<double> > matInv);
        void WW(double diffElement, double cofvar);
        void W(double diffElement, double cofvar);
        double prodScal(std::vector<std::vector<double> > Mat1, std::vector<std::vector<double> > Mat2, int indiceAB, int indiceIJ);

        void intAret(std::vector<Node> coordAret);
        void intElem();

        int returnQ(std::string type);
        const int getId() const;

        const std::vector<int>& getNodeIDs() const;

        Node getNodeById(int nodeId) const;

};

#endif