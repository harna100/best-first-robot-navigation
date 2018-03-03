//
// Created by Paul-HP on 2/25/2018.
//

#ifndef AI_HW3_NODE_H
#define AI_HW3_NODE_H

#include "NodeType.h"
struct Node {
    int x;
    int y;
    char rawChar;
    double weight;
    NodeType nodeType;
    bool wasVisited;

    bool operator==(const Node &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool operator!=(const Node &rhs) const {
        return !(rhs == *this);
    }
};

#endif //AI_HW3_NODE_H
