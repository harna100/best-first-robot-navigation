//
// Created by Paul on 2/28/2018.
//

#ifndef AI_HW3_MANHATTANFRINGE_H
#define AI_HW3_MANHATTANFRINGE_H


#include "Fringe.h"

class ManhattanFringe: Fringe {
public:
    ManhattanFringe(GridMap *gridMap);
    void insertNode(Node *toInsert, Node* possibleParent) override;
    Node *popNode() override;
    void calculateWeights() override;
    void printGridWeights();
    void traverse(Node *node) override;
    Node *findPath();
    void printPath(Node *node);
    private:
    protected:
    void printGrid();



};

#endif //AI_HW3_MANHATTANFRINGE_H
