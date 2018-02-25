#ifndef PARSER_H
#define PARSER_H

class Parser
{

	public:
		int n = -1;

		Parser();
		~Parser();
		char** parseFile(std::string fileName);
		int getDimension();
	private:
	protected:
	
	
};

#endif