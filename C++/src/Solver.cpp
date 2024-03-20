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
#include "Solver.hpp"


Solver::Solver(Mesh& mesh_, FEMParameters parameters_) : 
                mesh(mesh_), 
                parameters(parameters_),
                elementList(mesh_.getElements()),
                edgeList(mesh_.getEdges())
                {
    ptsNb = mesh.getNodesNumber();

    NbLine = ptsNb;
    NbCoeff = 0;
    for(int i = 0 ; i < NbLine ; i++){
        NbCoeff += i;
    }

    A = std::vector<double>(NbLine + NbCoeff, 0.0);
    b = std::vector<double>(NbLine, 0.0);

    A2 = std::vector<std::vector<double> >(NbLine, std::vector<double>(NbLine, 0.0));
    b2 = std::vector<double>(NbLine, 0.0);


    AdPrCoefLi = std::vector<int>(NbLine, 0);
    AdSuccLi = std::vector<int>(NbCoeff, 0);
    NumCol = std::vector<int>(NbCoeff, -1);

    NextAd = 1;

}

void Solver::assemble(){
    
    cout << "\nAssembling the matrix : ..." << endl;

//Integrate on the elements
    for(auto element : elementList){

        int nodeNumberElement = element.getNodeNumber();
        std::vector<std::vector<double> > MatElem(nodeNumberElement, std::vector<double>(nodeNumberElement, 0.0));

        std::vector<double> SMbrElem(nodeNumberElement, 0.0);
    
        element.intElem(MatElem, SMbrElem);

        FEMUtilities::printMat(MatElem, "MatLem");

        const std::vector<int>& nodesIds = element.getNodeIDs();
        for(int i = 0 ; i < nodeNumberElement ; i++){
            int I = nodesIds[i];
            b[I-1] += SMbrElem[i];
            b2[I-1] += SMbrElem[i];
            for(int j = 0 ; j <= i ; j++){
                int J = nodesIds[j];
                if(I > J){
                    A2[I-1][J-1] += MatElem[i][j];
                } else if (J > I){
                    A2[J-1][I-1] += MatElem[i][j];
                } else{
                    A2[I-1][J-1] += MatElem[i][j];
                }
                // if(I > J){
                //     assmat(I,J, MatElem[i][j], AdPrCoefLi, NumCol, AdSuccLi, A.data() + NbLine, NextAd);
                // }
                // else if(I < J){
                //     assmat(J, I, MatElem[i][j],AdPrCoefLi, NumCol, AdSuccLi, A.data() + NbLine, NextAd);
                // }
                    
                // else {
                //     A[I-1] += MatElem[i][j];
                // }
            }
        }
        // FEMUtilities::printVec(AdPrCoefLi, "AdPrCoefLi");
        // element.impCalEl(3,2,3, MatElem, SMbrElem, {0,0,0}, {0,0,0});
    }

//Integrate on the edges
    for(auto edge : edgeList){

        if(isDir0Edge(edge.getLabel())){
            continue;
        } else if (isDirNHEdge(edge.getLabel())) {
            for(auto node : edge.getNodeList()){
                A2[node.getId()-1][node.getId()-1] += FEMProblem::UD({node.getX(), node.getY()});
            }
        } else if (isNeumannEdge(edge.getLabel())) {
            int nodeNumberAret = edge.getNodeNumber();
            std::vector<std::vector<double> > MatAret(nodeNumberAret, std::vector<double>(nodeNumberAret, 0.0));

            std::vector<double> SMbrElem(nodeNumberAret, 0.0);
        
            edge.intAret(MatAret, SMbrElem, edge.getNodeList());

            const std::vector<int>& nodesIds = edge.getNodeIDs();
            for(int i = 0 ; i < nodeNumberAret ; i++){
                int I = nodesIds[i];
                b[I-1] += SMbrElem[i];
                b2[I-1] += SMbrElem[i];
                for(int j = 0 ; j < i ; j++){
                    int J = nodesIds[j];
                    if(I > J){
                        A2[I-1][J-1] += MatAret[i][j];
                    } else if (J > I){
                        A2[J-1][I-1] += MatAret[i][j];
                    } else{
                        A2[I-1][J-1] += MatAret[i][j];
                    }
                //     if(I > J){
                //         assmat(I,J, MatAret[i][j], AdPrCoefLi, NumCol, AdSuccLi, A.data() + NbLine, NextAd);
                //     }
                //     else if(I < J){
                //         assmat(J, I, MatAret[i][j],AdPrCoefLi, NumCol, AdSuccLi, A.data() + NbLine, NextAd);
                //     }
                        
                //     else {
                //         A[I-1] += MatAret[i][j];
                //     }
                }
            }
        }
    }


}

bool Solver::isNeumannEdge(const int labelEdge){
    for(auto label : parameters.getNeumannLabels()){
        if(labelEdge == std::stoi(label)){
            return true;
        }
    }
    return false;
}

bool Solver::isDir0Edge(const int labelEdge){
    for(auto label : parameters.getHomogeneousDirichletLabels()){
        if(labelEdge == std::stoi(label)){
            return true;
        }
    }
    return false;
}

bool Solver::isDirNHEdge(const int labelEdge){
    for(auto label : parameters.getDirichletLabels()){
        if(labelEdge == std::stoi(label)){
            return true;
        }
    }
    return false;
}



void Solver::assmat(int I, int J, double X, std::vector<int>& AdPrCoefLi, std::vector<int>& NumCol,
            std::vector<int>& AdSuccLi, double * Matrice, int& NextAd) {
    int IAD = AdPrCoefLi[I - 1];

    if (I <= J) {
        std::cout << "*Bug* The assmat function n'est utilisée que pour l'assemblage de la partie triangulaire stricte. Vous êtes sur le coefficient (" << I << "," << J << ")." << std::endl;
        exit(EXIT_FAILURE);
    }

    if (IAD > 0) {
        // La ligne I a déjà été rencontrée : recherche de la colonne J
        while (NumCol[IAD - 1] != J) {
            // Parcours des éléments de la ligne I
            int NXT = AdSuccLi[IAD - 1];
            if (NXT <= 0)
                break;
            IAD = NXT;
        }

        // L'élément A(i,j) existe : on l'incrémente et on sort
        *(Matrice + IAD - 1) += X;
        return;
    } else {
        // Création de la ligne I
        AdPrCoefLi[I - 1] = NextAd;
    }

    // Création de la colonne J
    AdSuccLi[IAD - 1] = NextAd;

    // Création du coefficient A(i,j) (nouvelle ligne ou colonne)
    NumCol[NextAd - 1] = J;
    *(Matrice + NextAd - 1) = X;
    AdSuccLi[NextAd - 1] = 0;
    NextAd++;
}


void Solver::printB(){
    std::cout << "Second member b : \n";
    for(auto el : b){
        std::cout << el << " ";
    }
    std::cout << endl;
}


void Solver::printA(){
    std::cout << "Matrix A : \n";

    // for(int i = 0 ; i < NbLine ; i++){
    //     for(int j = 0 ; j < i ; j++){
    //         cout << A[NbLine+j+NbLine*i] << " ";
    //     } 
    //     cout << A[i] << endl;
    // }    
    for(auto it : A){
        cout << it << " ";
    }
}




void Solver::AFFSMD() {
    int Lmin, Lmax;

    std::cout << "****** Affichage de la S.M.D. ******" << std::endl;

    do {
        std::cout << "Donner, dans l'intervalle [1," << NbLine << "], les indices min et max des lignes à afficher. Taper q pour arrêter." << std::endl;
        std::cin >> Lmin;
        if (std::cin.fail()) {
            // Gestion de l'entrée non valide (q pour quitter)
            std::cin.clear();  // Réinitialiser le flux d'entrée
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignorer la ligne invalide
            break;
        }
        std::cin >> Lmax;

        if (Lmin > Lmax || Lmin < 1 || Lmax > NbLine) {
            std::cout << "Indices invalides. Réessayez." << std::endl;
        } else {
            std::cout << std::endl;
            for (int i = Lmin; i <= Lmax; ++i) {
                std::cout << "Ligne " << i << ": SecMbr " << b[i] << std::endl;
                // std::cout << "Ligne " << i << ": SecMbr " << b[i] << " Nuddir " << NumDLDir[i] << " Valdir " << ValDLDir[i] << std::endl;
            }

            std::cout << "=== MATRICE ===========================" << std::endl;
            if (Lmin == 1) {
                std::cout << "--- Ligne 1 ---" << std::endl;
                std::cout << "Col 1 : " << A[0] << std::endl;
                Lmin = 2;
            }

            for (int i = Lmin; i <= Lmax; ++i) {
                std::cout << "--- Ligne " << i << " ---" << std::endl;
                int j = AdPrCoefLi[i - 1];
                while (j != 0) {
                    std::cout << "Col " << NumCol[j] << " : " << A[NbLine + j] << std::endl;
                    j = AdSuccLi[j];
                }
                std::cout << "Col " << i << " : " << A[i] << std::endl;
            }
        }
    } while (true);
}


