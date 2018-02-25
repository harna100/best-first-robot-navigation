#ifndef PARSER_H
#define PARSER_H

class Parser
{

	public:
		char** gridMap;//map to be navigated
		int n = -1; //dimensions of the grid

		Parser();
		~Parser();
		char** parseFile(std::string fileName);
		int getDimension();
	private:
	protected:
	
	
};

#endif