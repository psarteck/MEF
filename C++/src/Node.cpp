// Node.cpp
#include "Node.h"

Node::Node(double x_, double y_, double z_, int id_) : x(x_), y(y_), z(z_), id(id_) {}

Node::Node(double x_, double y_, double z_) : x(x_), y(y_), z(z_), id(-1) {}

Node::Node(double x_, double y_) : x(x_), y(y_), z(0.0), id(-1.0) {}

Node::Node(double x_) : x(x_), y(0.0), z(0.0), id(-1.0) {}

double Node::getX() const{
    return x;
}

double Node::getY() const{
    return y;
}

double Node::getZ() const{
    return z;
}

int Node::getId() const{
    return id;
}

void Node::setX(double x_){
    x = x_;
}

void Node::setY(double y_){
    y = y_;
}

void Node::setZ(double z_){
    z = z_;
}





// // Explicit instantiation for types 
// template class Node<double>;
// template class Node<float>;
