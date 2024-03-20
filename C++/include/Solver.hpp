/*---------------------------------------------------------------------------*\

 ██████╗ ██╗  ██╗██╗   ██╗     ███████╗███╗   ███╗
██╔═══██╗╚██╗██╔╝╚██╗ ██╔╝     ██╔════╝████╗ ████║
██║   ██║ ╚███╔╝  ╚████╔╝█████╗█████╗  ██╔████╔██║
██║   ██║ ██╔██╗   ╚██╔╝ ╚════╝██╔══╝  ██║╚██╔╝██║
╚██████╔╝██╔╝ ██╗   ██║        ██║     ██║ ╚═╝ ██║
 ╚═════╝ ╚═╝  ╚═╝   ╚═╝        ╚═╝     ╚═╝     ╚═╝
 * 
 * Copyright (C) 2024 by Matthieu PETIT
\*---------------------------------------------------------------------------*/
#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include "Mesh.hpp"
#include "FEMParameters.hpp"

class Solver {

    private : 
        std::vector<double> A;
        std::vector<double> b;

        std::vector<std::vector<double> > A2;
        std::vector<double> b2;


        std::vector<int> AdPrCoefLi;
        std::vector<double> SecMember;
        std::vector<double> NumDLDir;
        std::vector<double> ValDLDir;

        std::vector<int> AdSuccLi;
        std::vector<int> NumCol;
        int NextAd;

        int ptsNb; 
        int NbLine;
        int NbCoeff;

        Mesh mesh;
        const std::vector<Element>& elementList;
        const std::vector<Edge>& edgeList;
        FEMParameters parameters;
        
    public : 
        Solver(Mesh& mesh_, FEMParameters parameters_);

        void assemble();

        bool isNeumannEdge(const int labelEdge);
        
        bool isDir0Edge(const int labelEdge);
        
        bool isDirNHEdge(const int labelEdge);



        void assmat(int I, int J, double X, std::vector<int>& AdPrCoefLi, std::vector<int>& NumCol,
            std::vector<int>& AdSuccLi, double * Matrice, int& NextAd);

        void AFFSMD();

        void printB();
        void printA();

        std::vector<std::vector<double> >& getA2(){return A2;}
        std::vector<double>&  getb(){return b;}
};

#endif
