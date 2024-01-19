#ifndef QUADRATURE_H
#define QUADRATURE_H

#include <string>
#include <vector>
#include "Node.h"

class Quadrature{
private:
    std::string methodName;
    std::string elementType;
    int order;

    std::vector<double> weights;
    std::vector<std::vector<double> > points;
public:
    Quadrature(std::string methodName_, std::string elementType_, int order_);

    void weightsPoints(std::string elementType);

};



#endif