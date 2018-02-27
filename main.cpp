#include <iostream>
#include "Parser.h"


using namespace std;

int main(int argc, char **argv){
	Parser *p = new Parser();
	GridMap* gridMap = p->parseFile("sampleFile.txt");
	Node** grid = gridMap->getGrid();
	cout << "Parsed file\n";
	for (int i=0; i<5; ++i)
	{
		for (int j=0; j<5; ++j)
		{
			if (j==4)
			{
				cout<<grid[i][j].rawChar<<endl;
			}
			else
			{
				cout<<grid[i][j].rawChar;
			}
		}
	}
	cout << "Finished reading grid\n";
	return 0;
}