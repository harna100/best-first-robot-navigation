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
        nodesToCompare = std::list<Node*>();
    }

    virtual void insertNode(Node* toInsert) = 0;
    virtual Node* popNode() = 0;
    virtual void calculateWeights() = 0;
    std::list<Node*> getFringe() {
        return this->nodesToCompare;
    };
    GridMap* getGridMap(){
        return this->gridMap;
    }
    private:
        std::list<Node*> nodesToCompare;
        GridMap* gridMap;
    protected:
};

#endif //AI_HW3_FRINGE_H
