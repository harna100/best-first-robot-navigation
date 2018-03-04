//
// Created by Christine on 3/3/2018.
//

#ifndef AI_HW3_AMANHATTANFRINGE_H
#define AI_HW3_AMANHATTANFRINGE_H


#include "Fringe.h"

class AManhattanFringe: Fringe {
public:
    AManhattanFringe(GridMap *gridMap);
    void insertNode(Node *toInsert, Node* possibleParent) override;
    Node *popNode() override;
    void calculateWeights() override;
    void traverse(Node *node) override;
    Node *findPath();
    void printPath(Node *node);
private:
protected:
    void printGrid();
};


#endif //AI_HW3_AMANHATTANFRINGE_H
