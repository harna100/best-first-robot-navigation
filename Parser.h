#ifndef PARSER_H
#define PARSER_H

#include "Node.h"

class Parser
{

	public:
		int n = -1;

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