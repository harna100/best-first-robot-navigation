//
// Created by Christine on 3/3/2018.
//

#include "AEuclideanFringe.h"
#include <cmath>
#include <iostream>

using namespace std;

void AEuclideanFringe::insertNode(Node *toInsert, Node *possibleParent) {

    list<Node*>::iterator iterator;
    if (toInsert->wasVisited==true)
    {
        return;
    }
    toInsert->parent = possibleParent;

    toInsert->totalPathCost = possibleParent->totalPathCost+1;

    for (iterator = this->nodesToCompare.begin(); iterator != this->nodesToCompare.end(); ++iterator) {
        Node* currentNode = *iterator;
        if(toInsert->totalPathCost < currentNode->totalPathCost){
            toInsert->wasVisited = true;
            this->nodesToCompare.insert(iterator, toInsert);
            return;
        }
    }
    toInsert->wasVisited = true;
    this->nodesToCompare.insert(iterator, toInsert);

}

Node *AEuclideanFringe::popNode() {
    Node* toReturn = *(this->nodesToCompare.begin());
    if(toReturn == nullptr){
        throw "No path";
    }
    this->nodesToCompare.pop_front();
    return toReturn;
}

void AEuclideanFringe::calculateWeights() {
    GridMap* gridMap = this->gridMap;
    Node* goalNode =gridMap->getGoal();
    int x1 = goalNode->r;
    int y1 = goalNode->c;
    int x2;
    int y2;
    int dimension =gridMap->getDimension();
    cout<<dimension<<endl;

    Node*** grid = gridMap->getGrid();
    Node *currentNode;
    for (int i = 0; i<dimension; ++i)
    {
        for(int j = 0; j<dimension; ++j)
        {
            currentNode = grid[i][j];
            if (currentNode->nodeType !=Obstacle)//may need to account for Unknown type?
            {
                x2 = currentNode->r;
                y2 = currentNode->c;
                currentNode->weight = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
            }
            else
            {
                currentNode->weight = INFINITY;
            }
        }
    }
}

void AEuclideanFringe::traverse(Node *node) {

    int x = node->r;
    int y = node->c;

    Node*** grid = this->gridMap->getGrid();

    if ((y-1) >= 0 && grid[x][y-1]->nodeType!=Obstacle)
    {
        Node* toInsert = grid[x][y-1];
        this->insertNode(toInsert, node);
    }

    if((y+1 < this->gridMap->getDimension()) && grid[x][y+1]->nodeType!=Obstacle)
    {
        Node* toInsert = grid[x][y+1];
        this->insertNode(toInsert, node);
    }
    if((x-1) >= 0 && grid[x-1][y]->nodeType!=Obstacle)
    {
        Node* toInsert = grid[x-1][y];
        this->insertNode(toInsert, node);
    }
    if((x+1) < this->gridMap->getDimension() && grid[x+1][y]->nodeType != Obstacle)
    {
        Node* toInsert = grid[x+1][y];
        this->insertNode(toInsert, node);
    }
}

AEuclideanFringe::AEuclideanFringe(GridMap *gridMap){
    this->gridMap = gridMap;
}

Node *AEuclideanFringe::findPath() {
    int startRow = this->gridMap->getStart()->r;
    int startColumn = this->gridMap->getStart()->c;

    Node* currentNode = this->gridMap->getGrid()[startRow][startColumn];
    while(currentNode->nodeType!=Goal)
    {
        traverse(currentNode);
        currentNode = this->popNode();
    }
    return this->gridMap->getGrid()[currentNode->r][currentNode->c];
}

void AEuclideanFringe::printPath(Node *node) {
    Node* currentNode = node->parent;
    this->stepsTaken = 1;
    while(currentNode->nodeType!=Initial)
    {
        currentNode->nodeType = SelectedPath;
        currentNode->rawChar = 'o';
        currentNode = currentNode->parent;
        ++stepsTaken;
    }
    this->printGrid();
}

void AEuclideanFringe::printGrid()
{
    GridMap* gridMap = this->gridMap;
    int dimension =gridMap->getDimension();

    Node*** grid = gridMap->getGrid();
    Node* currentNode;
    for (int i = 0; i<dimension; ++i)
    {
        for(int j = 0; j<dimension; ++j)
        {
            currentNode = grid[i][j];
            if (j==dimension-1)//may need to account for Unknown type?
            {
                cout<<currentNode->rawChar<<endl;
            }
            else
            {
                cout<<currentNode->rawChar<<" ";
            }
        }
    }

    cout<<"Number of steps taken: "<<this->stepsTaken<<endl;
    cout<<"Number of nodes: "<<this->nodesToCompare.size()<<endl;
}
