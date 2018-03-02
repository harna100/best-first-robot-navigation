//
// Created by Paul on 2/28/2018.
//

#include "ManhattanFringe.h"
#include <iostream>
#include <cmath>

using namespace std;

void ManhattanFringe::insertNode(Node *toInsert) {
    list<Node*>::iterator iterator;

    for (iterator = this->nodesToCompare.begin(); iterator != this->nodesToCompare.end(); ++iterator) {
        Node* currentNode = *iterator;
        if(toInsert->weight < currentNode->weight){
            this->nodesToCompare.insert(iterator, toInsert);
        }
    }
    this->nodesToCompare.insert(iterator, toInsert);
}

Node *ManhattanFringe::popNode() {
    Node* toReturn = *(this->nodesToCompare.begin());
    this->nodesToCompare.pop_front();
    return toReturn;
}

void ManhattanFringe::calculateWeights() {
    cout << "B" << endl;
    GridMap* gridMap = this->gridMap;
    Node goalNode = gridMap->getGoal();
    int x1 = goalNode.x;
    int y1 = goalNode.y;
    int x2;
    int y2;
    int dimension =gridMap->getDimension();
    cout << dimension << endl;

    Node** grid = gridMap->getGrid();
    Node *currentNode;
    for (int i = 0; i<dimension; ++i)
    {
        for(int j = 0; j<dimension; ++j)
        {
            currentNode = &(grid[i][j]);
            if (currentNode->nodeType !=Obstacle)//may need to account for Unknown type?
            {
                x2 = currentNode->x;
                y2 = currentNode->y;
                currentNode->weight = abs(x2-x1)+abs(y2-y1);
            }
            else
            {
                currentNode->weight = INFINITY;
            }
        }
    }
}


void ManhattanFringe::printGridWeights() {
    GridMap* gridMap = this->gridMap;
    int dimension =gridMap->getDimension();

    Node** grid = gridMap->getGrid();
    Node* currentNode;
    for (int i = 0; i<dimension; ++i)
    {
        for(int j = 0; j<dimension; ++j)
        {
            currentNode = &(grid[i][j]);
            if (j==dimension-1)//may need to account for Unknown type?
            {
                cout<<currentNode->weight<<endl;
            }
            else
            {
                cout<<currentNode->weight<<" ";
            }
        }
    }

}

ManhattanFringe::ManhattanFringe(GridMap *gridMap) {
    this->gridMap = gridMap;
}

void ManhattanFringe::traverse(Node *node) {

    int x = node->x;
    int y = node->y;

    Node** grid = this->gridMap->getGrid();

    if ((y-1) >= 0 && grid[x][y-1].nodeType!=Obstacle)
    {
        this->insertNode(&grid[x][y-1]);
    }

    else if((y+1 < this->gridMap->getDimension()) && grid[x][y+1].nodeType!=Obstacle)
    {
        this->insertNode(&grid[x][y+1]);
    }
    else if((x-1) >= 0 && grid[x-1][y].nodeType!=Obstacle)
    {
        this->insertNode(&grid[x-1][y]);
    }
    else if((x+1) < this->gridMap->getDimension() && grid[x+1][y].nodeType != Obstacle)
    {
        this->insertNode(&grid[x+1][y]);
    }
}
