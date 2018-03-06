//
// Created by Paul-HP on 2/27/2018.
//

#ifndef AI_HW3_FRINGE_H
#define AI_HW3_FRINGE_H

#include <list>
#include "Node.h"
#include "GridMap.h"

class Fringe {
    public:

    Fringe(GridMap *gridMap){
        this->gridMap = gridMap;
    }

    Fringe() {}

    virtual void insertNode(Node* toInsert, Node* possibleParent) = 0;
    virtual Node* popNode() = 0;
    virtual void calculateWeights() = 0;
    virtual void traverse(Node* node) = 0;

    private:

    protected:
        GridMap* gridMap;
        std::list<Node*> nodesToCompare;
        int stepsTaken;
        int numberNodes;

};

#endif //AI_HW3_FRINGE_H
