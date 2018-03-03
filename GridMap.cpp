//
// Created by Paul-HP on 2/27/2018.
//

#include "GridMap.h"

Node ***GridMap::getGrid(){
    return grid;
}

Node* GridMap::getGoal(){
    return goal;
}

Node* GridMap::getStart(){
    return start;
}

int GridMap::getDimension()
{
	return dimension;
}

GridMap::GridMap(Node ***grid, Node* goal, Node* start, int dimension) {
    this->grid = grid;
    this->goal = goal;
    this->start = start;
    this->dimension = dimension;
}

GridMap::~GridMap() {
    delete grid;
}
