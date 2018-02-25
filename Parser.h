#ifndef PARSER_H
#define PARSER_H

#include "Node.h"

class Parser
{

	public:
		char** gridMap;//map to be navigated
		int n = -1; //dimensions of the grid

		Parser();
		~Parser();
		Node** parseFile(std::string fileName);
		int getDimension();
	private:
        int dimension;
	protected:


    NodeType convertToNodeType(char charNode);
};

#endif