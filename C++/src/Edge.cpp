#include "Edge.h"

// TO DO CHANGE THE TYPE IN THE CONSTRUCTOR
Edge::Edge(Node& node1_, Node& node2_, int label_) : label(label_), type("S1"){

    nodeList.push_back(node1_);
    nodeList.push_back(node2_);

    nodeIdList.push_back(node1_.getId());
    nodeIdList.push_back(node2_.getId());

    // quadraMethodS1 = Quadrature();

}

// TO DO CHANGE THE TYPE IN THE CONSTRUCTOR
Edge::Edge(std::vector<Node> nodeList_, int label_) : nodeList(nodeList_), label(label_), type("S1"){
    for(auto node : nodeList){
        nodeIdList.push_back(node.getId());
    }
}


void Edge::intAret(std::vector<std::vector<double> >& elemMatrix, std::vector<double>& fElem, std::vector<Node> coordAret){

    // TO DO : MOVE IN Edge class ??
    cout << "azeazea" << endl;
    int d = 1;
    
    int q = FEMIntegrale::returnQ(type);
    
    quadraMethodS1.weightsPoints(type);
    
    
    for(int indicepts = 0 ; indicepts < q ; indicepts ++){
        
        std::vector<Node> pts = quadraMethodS1.getPoints();
        std::vector<double> pds = quadraMethodS1.getWeights();

        std::vector<double> baseFct = FEMIntegrale::baseFunctions(pts[indicepts], type);

        std::vector<std::vector<double> > baseDerFct = FEMIntegrale::baseDerFunctions(pts[indicepts], type);
        
        std::vector<std::vector<double> > Jcob = FEMIntegrale::matJacob(coordAret, baseDerFct, type);
        
        std::vector<double> imagPoint = FEMIntegrale::transFK(coordAret, baseFct);

        double eltdif = pds[indicepts] * sqrt(Jcob[0][0]*Jcob[0][0] + Jcob[0][1]*Jcob[0][1]);
        
        double cofvarWW = FEMProblem::BN(imagPoint);
        
        FEMIntegrale::WW(nodeList, baseFct, eltdif, cofvarWW, elemMatrix);
        

    //     // TODO BRING THE NUMBER OF AR ET ?
        int numAret = 1; // ?
        double cofvarW = FEMProblem::FN(imagPoint, numAret);

        FEMIntegrale::W(nodeList, baseFct, eltdif, cofvarW, fElem);
        
    }

}


// bool Edge::operator==(const Edge& other) const {
//     return ((node1 == other.node1) && (node2 == other.node2) || (node2 == other.node1) && (node1 == other.node2));

//     for(auto node : nodeList){
//         if()
//     }
// }


// bool Edge::isOnEdge(const std::vector<Edge>& edgeList){
//     for(auto edge : edgeList){
//         if(*this == edge){
//             return true;
//         }
//     }
//     return false;
// }

void Edge::setLabel(int newlabel){
    label = newlabel;
}

int Edge::getLabel(){
    return label;
}

int Edge::getNodeNumber(){
    return nodeList.size();
}

const std::vector<int>& Edge::getNodeIDs() const{
    return nodeIdList;
}

std::vector<Node> Edge::getNodeList(){
    return nodeList;
}

void Edge::printEdge(){
    std::cout << "EdgeLabel : " << getLabel() << std::endl;
    for(auto node : nodeList){
        std::cout << node.getId() << " | ";
    }
    std::cout << std::endl;
}