//
// Created by Paul-HP on 2/27/2018.
//

#ifndef AI_HW3_EUCLIDEANFRINGE_H
#define AI_HW3_EUCLIDEANFRINGE_H


#include "Fringe.h"

class EuclideanFringe: Fringe{
    public:
        EuclideanFringe(GridMap *gridMap);
private:

public:
    void insertNode(Node* toInsert) override;
    Node *popNode() override;
    void calculateWeights() override;
    void printGridWeights();
    private:
    protected:
};


#endif //AI_HW3_EUCLIDEANFRINGE_H
