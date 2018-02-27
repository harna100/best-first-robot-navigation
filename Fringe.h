//
// Created by Paul-HP on 2/27/2018.
//

#ifndef AI_HW3_FRINGE_H
#define AI_HW3_FRINGE_H

#include "Node.h"

virtual class Fringe {
    public:
        virtual void insertNode(Node toInsert) = 0;
        virtual Node* popNode() = 0;
    private:
    protected:
};

#endif //AI_HW3_FRINGE_H