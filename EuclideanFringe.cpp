//
// Created by Paul-HP on 2/27/2018.
//

#include "EuclideanFringe.h"
#include <cmath>
#include <iostream>

using namespace std;
void EuclideanFringe::insertNode(Node* toInsert) {
    list<Node*>::iterator iterator;
    if (toInsert->wasVisited==true)
    {
        return;
    }

    for (iterator = this->nodesToCompare.begin(); iterator != this->nodesToCompare.end(); ++iterator) {
        Node* currentNode = *iterator;
        if(toInsert->weight < currentNode->weight){
            this->nodesToCompare.insert(iterator, toInsert);
        }
    }
    this->nodesToCompare.insert(iterator, toInsert);
    toInsert->wasVisited = true;
}

Node *EuclideanFringe::popNode() {
    Node* toReturn = *(this->nodesToCompare.begin());
    this->nodesToCompare.pop_front();
    return toReturn;
}

void EuclideanFringe::calculateWeights()
{
    cout<<"A"<<endl;
    GridMap* gridMap = this->gridMap;
    Node goalNode =gridMap->getGoal();
    int x1 = goalNode->x;
    int y1 = goalNode->y;
    int x2;
    int y2;
    int dimension =gridMap->getDimension();
    cout<<dimension<<endl;

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
                currentNode->weight = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
            }
            else
            {
                currentNode->weight = INFINITY;
            }
        }
    }
}


void EuclideanFringe::printGridWeights()
{
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

void EuclideanFringe::traverse(Node *node)
{
    int x = node.x;
    int y = node.y;

    Node** grid = this->gridMap->grid;

    if ((y-1)>=0&&grid[x][y-1].nodeType!=Obstacle)
    {
        this->insertNode(grid[x][y-1]);
    }

    else if((y+1<this->gridMap->getDimension())&&grid[x][y+1].nodeType!=Obstacle)
    {
        this->insertNode(grid[x][y+1])
    }
    else if((x-1)>=0&&grid[x-1][y].nodeType!=Obstacle)
    {
        this->insertNode(grid[x-1][y]);
    }
    else if((x+1)<this->gridMap->getDimension()&&grid[x+1][y])
    {
        this->insertNode(grid[x+1][y]);
    }
    
}

EuclideanFringe::EuclideanFringe(GridMap *gridMap) {
    this->gridMap = gridMap;
}
