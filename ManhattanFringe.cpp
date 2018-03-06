//
// Created by Paul on 2/28/2018.
//

#include "ManhattanFringe.h"
#include <iostream>
#include <cmath>

using namespace std;

void ManhattanFringe::insertNode(Node *toInsert, Node *possibleParent) {
    list<Node*>::iterator iterator;

    if(toInsert->wasVisited == true){
        return;
    }

    toInsert->parent = possibleParent;


    for (iterator = this->nodesToCompare.begin(); iterator != this->nodesToCompare.end(); ++iterator) {
        Node* currentNode = *iterator;
        if(toInsert->weight < currentNode->weight){
            toInsert->wasVisited = true;
            this->nodesToCompare.insert(iterator, toInsert);
            return;
        }
    }
    this->nodesToCompare.insert(iterator, toInsert);
    toInsert->wasVisited = true;
}

Node *ManhattanFringe::popNode() {
    Node* toReturn = *(this->nodesToCompare.begin());
    if(toReturn == nullptr){
        throw "No path";
    }
    this->nodesToCompare.pop_front();
    return toReturn;
}

void ManhattanFringe::calculateWeights() {
    GridMap* gridMap = this->gridMap;
    Node* goalNode = gridMap->getGoal();
    int x1 = goalNode->r;
    int y1 = goalNode->c;
    int x2;
    int y2;
    int dimension =gridMap->getDimension();
    cout << dimension << endl;

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

ManhattanFringe::ManhattanFringe(GridMap *gridMap) {
    this->gridMap = gridMap;
}

void ManhattanFringe::traverse(Node *node) {

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


Node* ManhattanFringe::findPath()
{
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

void ManhattanFringe::printPath(Node *node) {
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

void ManhattanFringe::printGrid() {
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