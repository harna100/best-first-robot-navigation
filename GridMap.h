//
// Created by Paul-HP on 2/27/2018.
//

#ifndef AI_HW3_GRIDMAP_H
#define AI_HW3_GRIDMAP_H


#include "Node.h"

class GridMap {
    public:
    GridMap(Node **grid, Node &goal, Node &start, int dimension);

    virtual ~GridMap();

    Node **getGrid();
    Node getGoal();
    Node getStart();
    int getDimension();

    private:
        Node** grid;
        Node goal;
        Node start;
        int dimension;
    protected:
};


#endif //AI_HW3_GRIDMAP_H
