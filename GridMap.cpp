//
// Created by Paul-HP on 2/27/2018.
//

#include "GridMap.h"

Node **GridMap::getGrid(){
    return grid;
}

Node GridMap::getGoal(){
    return goal;
}

Node GridMap::getStart(){
    return start;
}

GridMap::GridMap(Node **grid, Node &goal, Node &start) {
    this->grid = grid;
    this->goal = goal;
    this->start = start;
}

GridMap::~GridMap() {
    delete grid;
}
