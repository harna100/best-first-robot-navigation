#include <iostream>
#include "Parser.h"
#include <fstream>

using namespace std;



Parser::Parser(){
	cout << "Created Parser\n";
};

char** Parser::parseFile(std::string fileName)
{
	char** gridMap;
	ifstream theFile;
	theFile.open(fileName.c_str());

	int lineCount = 0;
	string line;
	if(theFile.is_open())
	{
		while(getline(theFile, line))
		{
			if (lineCount == 0)
			{
				n = atoi(line.c_str());
				gridMap = new char* [n];
			}

			else
			{
				gridMap[lineCount-1] = new char[n];
				for (int i = 0; i<line.length(); ++i)
				{
					gridMap[lineCount-1][i] = line[i];
				}
			}
			++lineCount;
		}
	}
	return gridMap;
}

int Parser::getDimension()
{
	return n;
}

Parser::~Parser(){

}