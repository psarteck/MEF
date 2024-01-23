#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include "Node.h"

class Edge{
    private :
        Node node1;
        Node node2;
        int label;
    public :
        Edge(Node& node1_, Node& node2_, int label_);
        
};

#endif