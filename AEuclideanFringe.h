//
// Created by Christine on 3/3/2018.
//

#ifndef AI_HW3_AEUCLIDEANFRINGE_H
#define AI_HW3_AEUCLIDEANFRINGE_H


#include "Fringe.h"

class AEuclideanFringe: Fringe{

    public:
    AEuclideanFringe(GridMap *gridMap);

    void insertNode(Node *toInsert, Node *possibleParent) override;

    Node *popNode() override;

    void calculateWeights() override;

    void traverse(Node *node) override;

    Node* findPath();

    void printPath(Node *node);

    void printGrid();
};


#endif //AI_HW3_AEUCLIDEANFRINGE_H
