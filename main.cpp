#include <iostream>
#include "Parser.h"
#include "EuclideanFringe.h"
#include "ManhattanFringe.h"


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

	string fileName = "sample10.txt";
	GridMap *forEuclid = p->parseFile(fileName);
	cout << "parsed euclid\n";
	GridMap *forManhat = p->parseFile(fileName);
	cout << "parsed manhat\n";
	//GridMap *forCombinedPt1 = p->parseFile(fileName);
	//GridMap *forCombinedPt2 = p->parseFile(fileName);


	cout << "parsed\n";
    EuclideanFringe *euclideanFringe = new EuclideanFringe(forEuclid);
	euclideanFringe->calculateWeights();
	cout << "calculated euclid\n";
	euclideanFringe->printGridWeights();//this method is just for checking it actually calculated and assigned weights correctly
	cout << "printed euclid\n";
	Node* euclidPath = euclideanFringe->findPath();
	cout << "found euclid path\n";
	euclideanFringe->printPath(euclidPath);
	cout << "printed euclid path\n";

/*	ManhattanFringe *manhattanFringe = new ManhattanFringe(forManhat);
	manhattanFringe->calculateWeights();
	manhattanFringe->printGridWeights();
	Node* manhatPath = manhattanFringe->findPath();
	manhattanFringe->printPath(manhatPath);*/




	return 0;
}