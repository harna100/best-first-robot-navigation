#include <iostream>
#include "Parser.h"
#include "EuclideanFringe.h"


using namespace std;

int main(int argc, char **argv){
	/*Parser *p = new Parser();
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
	cout << "Finished reading grid\n";*/


	Parser *p = new Parser();

	string fileName = "sampleFile.txt";
	GridMap *forEuclid = p->parseFile(fileName);
	GridMap *forManhat = p->parseFile(fileName);
	GridMap *forCombinedPt1 = p->parseFile(fileName);
	GridMap *forCombinedPt2 = p->parseFile(fileName);
	EuclideanFringe *euclideanFringe = new EuclideanFringe(forEuclid);
	euclideanFringe->calculateWeights();
	euclideanFringe->printGridWeights();//this method is just for checking it actually calculated and assigned weights correctly

	return 0;
}