#include <iostream>
#include "Parser.h"
#include "EuclideanFringe.h"
#include "ManhattanFringe.h"
#include "AEuclideanFringe.h"
#include "AManhattanFringe.h"


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

	string fileName = "sample80.txt";
	GridMap *forEuclid = p->parseFile(fileName);
	GridMap *forManhat = p->parseFile(fileName);
	GridMap *forAEuclid = p->parseFile(fileName);
	GridMap *forAManhat = p->parseFile(fileName);


    EuclideanFringe *euclideanFringe = new EuclideanFringe(forEuclid);
	euclideanFringe->calculateWeights();
	Node* euclidPath = euclideanFringe->findPath();
	euclideanFringe->printPath(euclidPath);


	ManhattanFringe *manhattanFringe = new ManhattanFringe(forManhat);
	manhattanFringe->calculateWeights();
	Node* manhatPath = manhattanFringe->findPath();
	manhattanFringe->printPath(manhatPath);

	AEuclideanFringe *aEuclideanFringe = new AEuclideanFringe(forAEuclid);
	aEuclideanFringe->calculateWeights();
	Node* aEuclidPath = aEuclideanFringe->findPath();
	aEuclideanFringe->printPath(aEuclidPath);

    AManhattanFringe *aManhattanFringe = new AManhattanFringe(forAManhat);
    aManhattanFringe->calculateWeights();
    Node* aManhatPath = aManhattanFringe->findPath();
    aManhattanFringe->printPath(aManhatPath);




	return 0;
}