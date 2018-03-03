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


void EuclideanFringe::printGridWeights()
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
    int x = node->r;
    int y = node->c;

    Node*** grid = this->gridMap->getGrid();

    if ((y-1) >= 0 && grid[x][y-1]->nodeType!=Obstacle)
    {
        Node* toInsert = grid[x][y-1];
        toInsert->parent = node;
        this->insertNode(toInsert);
    }

    if((y+1 < this->gridMap->getDimension()) && grid[x][y+1]->nodeType!=Obstacle)
    {
        Node* toInsert = grid[x][y+1];
        toInsert->parent = node;
        this->insertNode(toInsert);
    }
    if((x-1) >= 0 && grid[x-1][y]->nodeType!=Obstacle)
    {
        Node* toInsert = grid[x-1][y];
        toInsert->parent = node;
        this->insertNode(toInsert);
    }
    if((x+1) < this->gridMap->getDimension() && grid[x+1][y]->nodeType != Obstacle)
    {
        Node* toInsert = grid[x+1][y];
        toInsert->parent = node;
        this->insertNode(toInsert);
    }
    
}

Node* EuclideanFringe::findPath()
{
    int startRow = this->gridMap->getStart()->r;
    int startColumn = this->gridMap->getStart()->c;

    Node* currentNode = this->gridMap->getGrid()[startRow][startColumn];
    while(currentNode->nodeType!=Goal)
    {
        cout << "r: " << currentNode->r<< " c: " <<  currentNode->c<< endl;
        traverse(currentNode);
        currentNode = this->popNode();
    }
    cout<<"Find path finishing"<<endl;
    return this->gridMap->getGrid()[currentNode->r][currentNode->c];
}



EuclideanFringe::EuclideanFringe(GridMap *gridMap) {
    this->gridMap = gridMap;
}

void EuclideanFringe::printPath(Node *node) {
    Node* currentNode = node->parent;
    while(currentNode->nodeType!=Initial)
    {
        cout << "r: " << currentNode->r<< " c: " <<  currentNode->c<< endl;
        currentNode->nodeType = SelectedPath;
        currentNode->rawChar = 'o';
        currentNode = currentNode->parent;
    }
    cout<<"Finished setting selected"<<endl;
    this->printGrid();
}

void EuclideanFringe::printGrid() {
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
}
