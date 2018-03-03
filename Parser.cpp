#include <iostream>
#include "Parser.h"
#include <fstream>

using namespace std;



Parser::Parser(){
	cout << "Created Parser\n";
};

GridMap* Parser::parseFile(std::string fileName)
{
	Node** gridMap;
	Node goal;
	Node start;
	int dimension;
	ifstream theFile;
	theFile.open(fileName.c_str());

	int lineCount = 0;
	string line;
	if(theFile.is_open())
	{
		while(getline(theFile, line))
		{
			// first line of file contains the dimension
			if (lineCount == 0)
			{
				dimension = atoi(line.c_str());
				this->dimension = dimension;
				gridMap = new Node* [dimension];
			}
			else
			{
				gridMap[lineCount-1] = new Node[dimension];
				for (int i = 0; i<dimension; ++i)
				{
				    char currChar = line[i];

				    Node currNode = Node();
				    currNode.c = i;
				    currNode.r = lineCount-1;
				    currNode.rawChar = currChar;
				    currNode.nodeType = this->convertToNodeType(currChar);

					gridMap[lineCount-1][i] = currNode;
					currNode.wasVisited = false;

					if(currNode.nodeType == Goal){
					    goal = currNode;
					}
					else if(currNode.nodeType == Initial){
					    currNode.wasVisited = true;
						start = currNode;
					}
				}
			}
			++lineCount;
		}
	}
	return new GridMap(gridMap, goal, start, dimension);
}

int Parser::getDimension()
{
	return this->dimension;
}

NodeType Parser::convertToNodeType(char charNode){
    NodeType toReturn;
    switch(charNode){
		case '.':
			toReturn = Empty;
			break;
		case 'i':
			toReturn = Initial;
			break;
		case 'g':
            toReturn = Goal;
            break;
        case '+':
            toReturn = Obstacle;
            break;
        case 'o':
            toReturn = SelectedPath;
            break;
		default:
			toReturn = Unknown;
    }
    return toReturn;
}

Parser::~Parser(){
    cout << "Parser deleted\n";
}