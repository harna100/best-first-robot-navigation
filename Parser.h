#ifndef PARSER_H
#define PARSER_H

#include "Node.h"
#include "GridMap.h"

class Parser
{

	public:
		char** gridMap;//map to be navigated
		int n = -1; //dimensions of the grid

		Parser();
		~Parser();
		GridMap* parseFile(std::string fileName);

		int getDimension();
	private:
        int dimension;
	protected:


    NodeType convertToNodeType(char charNode);
};

#endif