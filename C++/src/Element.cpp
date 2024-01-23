#include "Element.h"


Element::Element(int id_, std::vector<int>& nodeIds, std::vector<Node>& nodes_)
    : id(id_), nodeIds(nodeIds), nodes(nodes_){
    // Assuming nodes and nodeIds have the same size
    // for (size_t i = 0; i < nodes.size() - 1; ++i) {
    //     edges.push_back(Edge(nodes[i], nodes[i + 1]));
    // }
    // edges.push_back(Edge(nodes.back(), nodes.front()));  // Closing the loop

    // elemMatrix = std::vector<std::vector<double> >(nodes.size(), std::vector<double>(nodes.size(), 0.0));
    // fElem = std::vector<double>(nodes.size(), 0.0);
}

void Element::baseFunctions(const Node& pts){
    if(type == "Q1"){            
        valBase.push_back(pts.getX() - pts.getX()*pts.getY());
        valBase.push_back(pts.getX()*pts.getY());
        valBase.push_back(pts.getY() - pts.getX()*pts.getY());
        valBase.push_back(pts.getX()*pts.getY() - pts.getY() - pts.getX() + 1);   
    }
    else if(type == "T1"){
        valBase.push_back(pts.getX());
        valBase.push_back(pts.getY());
        valBase.push_back(1 - pts.getX() - pts.getY());
    }
    else if(type == "S1"){
        valBase.push_back(pts.getX());
        valBase.push_back(1-pts.getX());
    }
    else{
            std::cout << "Error : Unkown element type." << std::endl;
    }
}

void Element::baseDerFunctions(const Node& pts){
    if(type == "Q1"){            
        valDerBase.push_back({1-pts.getY(), pts.getY(), -pts.getY(), pts.getY()-1});
        valDerBase.push_back({-pts.getX(), pts.getX(), 1-pts.getX(), pts.getX()- 1});   
    }
    else if(type == "T1"){
        valDerBase.push_back({1, 0, -1});
        valDerBase.push_back({0, 1, -1});
    }
    else if(type == "S1"){
        valDerBase.push_back({1, -1});
    }
    else{
            printf("\nError : Unkown element type.\n");
    }
}

std::vector<double> Element::transFK(std::vector<Node> selectNodes){
    // float **ai, float *valBase, int Pk, float *res){
    // TO DO Make it 3D
    std::vector<double> evaluatedPoint(2);
    for(int i = 0 ; i < selectNodes.size() ; i++){
        evaluatedPoint[0] += selectNodes[i].getX() * valBase[i];
        evaluatedPoint[1] += selectNodes[i].getY() * valBase[i];
    }
    return evaluatedPoint;
}


std::vector<std::vector<double> > Element::matJacob(std::vector<Node> selectNodes){

    // TO DOO MAKE IT 3D AND BETTER !!!!

    std::vector<std::vector<double>> Jcob(2, std::vector<double>(nodes.size(), 0.0));

    int d;
    if(type == "S1"){
        d = 1;
    }
    else{
        d = 2;
    }   

    for(int j = 0 ; j < d ; j++){
        for(int k = 0 ; k < selectNodes.size() ; k++){
            Jcob[0][j] += selectNodes[k].getX() * valDerBase[k][j];
        }
    }
    for(int j = 0 ; j < d ; j++){
        for(int k = 0 ; k < selectNodes.size() ; k++){
            Jcob[1][j] += selectNodes[k].getY() * valDerBase[k][j];
        }
    }
    return Jcob;
}


std::vector<std::vector<double> > Element::invert2x2(std::vector<std::vector<double> >& mat, double& det){
    // TO DO FAIRE MIEUX -> EIGEN ???

    // Eigen::MatrixXd matEigen = FEMUtilities::vector2EigenMatrix(mat); 

    std::vector<std::vector<double> > invMat(mat.size(), std::vector<double>(mat[0].size(), 0.0));

    det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    
    invMat[0][0] = 1/ det * mat[1][1];
    invMat[0][1] = -1/ det * mat[0][1];
    invMat[1][0] = -1/ det * mat[1][0];
    invMat[1][1] = 1/ det * mat[0][0];

    return invMat;

}


void Element::WW(double diffElement, double cofvar, std::vector<std::vector<double> >& elemMatrix){

	double coeff;
    // double cofvar = FEMProblem::A00(point);

	for (int i = 0; i < nodes.size() ; i++) {
    	coeff = diffElement*cofvar*valBase[i];
    	for (int j = 0 ; j < nodes.size() ; j++) {
      		elemMatrix[i][j] = elemMatrix[i][j] + coeff*valBase[j];
    	}
  	}
}

void Element::W(double diffElement, double cofvar, std::vector<double> fElem){
    for (int i = 0 ; i < nodes.size() ; i++) {
        fElem[i] += diffElement * cofvar * valBase[i];
  	}
}

void Element::ADWDW(double diffElement, std::vector<double> point, std::vector<std::vector<double> > cofvar, std::vector<std::vector<double> > matInv, std::vector<std::vector<double> >& elemMatrix){

    int i, j, alpha, beta;

	for (i = 0 ; i < nodes.size() ; i++) {
    	for (j = 0 ; j < nodes.size() ; j++) {
    		for(alpha = 0 ; alpha < 2 ; alpha++){
                float pdscai = prodScal(valDerBase, matInv, alpha, j);
                
    			for(beta = 0 ; beta < 2 ; beta++){
                    float pdscaj = prodScal(valDerBase, matInv, beta, i);
      				elemMatrix[i][j] += diffElement * cofvar[alpha][beta] * pdscai * pdscaj;
      			}
      		}
    	}
  	}

}

double Element::prodScal(std::vector<std::vector<double> > Mat1, std::vector<std::vector<double> > Mat2, int indiceAB, int indiceIJ){
    float somme = 0;
    for(int k = 0 ; k < 2 ; k++){
        somme += Mat1[indiceIJ][k]*Mat2[indiceAB][k];
    }
    return somme;
}


int Element::returnQ(std::string type){
	if(type == "Q1"){
		return 9;
	}
	else if(type == "T1"|| type == "S1"){
		return 3;
	}
    return 0;
}


void Element::intAret(std::vector<std::vector<double> >& elemMatrix, std::vector<double> fElem, std::vector<Node> coordAret){

    // TO DO : MOVE IN Edge class ??

    int d = 1;
    
    int q = returnQ("S1");
    
    quadraMethodS1.weightsPoints("S1");
    
    
    for(int indicepts = 0 ; indicepts < q ; indicepts ++){
        
        std::vector<Node> pts = quadraMethodS1.getPoints();
        std::vector<double> pds = quadraMethodS1.getWeights();

        baseFunctions(pts[indicepts]);

        baseDerFunctions(pts[indicepts]);
        
        std::vector<std::vector<double> > Jcob = matJacob(coordAret);
        
        std::vector<double> imagPoint = transFK(coordAret);

        double eltdif = pds[indicepts] * sqrt(Jcob[0][0]*Jcob[0][0] + Jcob[0][1]*Jcob[0][1]);
        
        double cofvarWW = FEMProblem::BN(imagPoint);
        
        WW(eltdif, cofvarWW, elemMatrix);
        

        // TODO BRING THE NUMBER OF AR ET ?
        int numAret = 1; // ?
        double cofvarW = FEMProblem::FN(imagPoint, numAret);

        W(eltdif, cofvarW, fElem);
        
    }

}

void Element::intElem(std::vector<std::vector<double> >& elemMatrix, std::vector<double>& fElem, std::vector<Node> selectNodes){
    
    int q = returnQ(type);

    quadraMethodS1.weightsPoints("T1");
    
    
    for(int indicepts = 0 ; indicepts < q ; indicepts ++){

        std::vector<Node> pts = quadraMethodS1.getPoints();
        std::vector<double> pds = quadraMethodS1.getWeights();

        baseFunctions(pts[indicepts]);
        baseDerFunctions(pts[indicepts]);
        std::vector<std::vector<double> > Jcob = matJacob(selectNodes);
        double det;
        std::vector<std::vector<double> > matInv = invert2x2(Jcob, det);
        
        std::vector<double> imagPoint = transFK(selectNodes);

        double eltdif = det * pds[indicepts];
        
        std::vector<std::vector<double> > cofvarAD(2, std::vector<double>(2,0.0));
        cofvarAD[0][0] = FEMProblem::A11(imagPoint);
        cofvarAD[0][1] = FEMProblem::A12(imagPoint);
        cofvarAD[1][0] = FEMProblem::A12(imagPoint);
        cofvarAD[1][1] = FEMProblem::A22(imagPoint);
        
        ADWDW(eltdif, imagPoint, cofvarAD, matInv, elemMatrix);

        double cofvarWW = FEMProblem::A00(imagPoint);
        
        WW(eltdif, cofvarWW, elemMatrix);
        
                
        double cofvarW = FEMProblem::FOMEGA(imagPoint);
        
        W(eltdif, cofvarW, fElem);
        
    }
}



void Element::cal1Elem(std::vector<std::vector<double> >& MatElem, std::vector<double>& SMbrElem,
              std::vector<int>& NuDElem, std::vector<double>& uDElem){
    for(int j = 0 ; j < nodes.size() ; j ++){
        NuDElem[j] = 1;
        uDElem[j] = 0;
    }
    for(int k = 0 ; k < nodes.size() ; k ++){
        SMbrElem[k] = 0;
        for(int l = 0 ; l < nodes.size() ; l++){
            MatElem[k][l] = 0;
        }
    }

    intElem(MatElem, SMbrElem, nodes);

}


void Element::impCalEl(int K, int typEl, int nbneel, std::vector<std::vector<double> > MatElem, std::vector<double> SMbrElem,
              std::vector<int> NuDElem, std::vector<double> uDElem){
    int i, j;
    std::cout << std::endl;
    std::cout << " ELEMENT=" << std::setw(3) << K
          << "    DE TYPE=" << std::setw(5) << typEl
          << "    NB NOEUDS=" << std::setw(2) << nbneel << std::endl;

    std::cout << " NuDElem   uDElem    SMbrElem    MatElem" << std::endl;
    for (int i = 0; i < nbneel; i++) {
        std::cout << std::setw(6) << NuDElem[i]
                << std::scientific << std::setw(14) << uDElem[i]
                << std::scientific << std::setw(14) << SMbrElem[i];
        for (int j = 0; j <= i; j++) {
            std::cout << std::scientific << std::setw(14) << MatElem[i][j];
        }
        std::cout << std::endl;
    }
}


const int Element::getId() const {  return id;  }

const std::vector<int>& Element::getNodeIDs() const {   return nodeIds;   }

Node Element::getNodeById(int nodeId) const {
    for (const Node& node : nodes) {
        if (node.getId() == nodeId) {
            return node;
        }
    }
    // Handle the case where the node with the specified ID is not found
    // You might want to throw an exception or handle it based on your needs.
    // For simplicity, we'll return the first node in the element.
    return nodes.front();
}
