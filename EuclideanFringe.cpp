//
// Created by Paul-HP on 2/27/2018.
//

#include "EuclideanFringe.h"

using namespace std;
void EuclideanFringe::insertNode(Node* toInsert) {
    list<Node*>::iterator iterator;

    for (iterator = this->getFringe().begin(); iterator != this->getFringe().end(); ++iterator) {
        Node* currentNode = *iterator;
        if(toInsert->weight < currentNode->weight){
            this->getFringe().insert(iterator, toInsert);
        }
    }
    this->getFringe().insert(iterator, toInsert);
}

Node *EuclideanFringe::popNode() {
    Node* toReturn = *(this->getFringe().begin());
    this->getFringe().pop_front();
    return toReturn;
}

EuclideanFringe::EuclideanFringe(GridMap *gridMap) : Fringe(gridMap) {

}
