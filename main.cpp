#include <iostream>
#include "Parser.h"


using namespace std;

int main(int argc, char **argv){
	Parser *p = new Parser();
	char**gridMap = p->parseFile("sampleFile.txt");

	for (int i=0; i<5; ++i)
	{
		for (int j=0; j<5; ++j)
		{
			if (j==4)
			{
				cout<<gridMap[i][j]<<endl;
			}
			else
			{
				cout<<gridMap[i][j];
			}
		}
	}
	return 0;
}