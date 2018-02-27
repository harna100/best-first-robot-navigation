//
// Created by Paul-HP on 2/27/2018.
//

#ifndef AI_HW3_GRIDMAP_H
#define AI_HW3_GRIDMAP_H


#include "Node.h"

class GridMap {
    public:
    GridMap(Node **grid, Node &goal, Node &start);

    virtual ~GridMap();

    Node **getGrid();
    Node getGoal();
    Node getStart();

private:
        Node** grid;
        Node goal;
        Node start;
    protected:
};


#endif //AI_HW3_GRIDMAP_H
