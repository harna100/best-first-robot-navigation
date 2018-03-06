#include <iostream>
#include "Parser.h"
#include "EuclideanFringe.h"
#include "ManhattanFringe.h"
#include "AEuclideanFringe.h"
#include "AManhattanFringe.h"


using namespace std;

int main(int argc, char **argv){

	string fileName;
	if(argc  > 1){
		fileName = argv[1];
	}
	else {
		cout << "No filename provided. Exiting program\n";
		return 1;
	}
	bool runAll = true;
	string specificRun;
	if(argc == 3){
		specificRun = argv[2];
		runAll = false;
	}

	Parser *p = new Parser();

	try {
		if(runAll || specificRun == "1"){
        	cout << "Strategy 1: "<<endl;
			GridMap *forEuclid = p->parseFile(fileName);
			EuclideanFringe *euclideanFringe = new EuclideanFringe(forEuclid);
			euclideanFringe->calculateWeights();
			Node* euclidPath = euclideanFringe->findPath();
			euclideanFringe->printPath(euclidPath);
			cout<<"********************"<<endl;
		}


		if(runAll || specificRun == "2"){
    		cout << "Strategy 2: \n";
			GridMap *forManhat = p->parseFile(fileName);
			ManhattanFringe *manhattanFringe = new ManhattanFringe(forManhat);
			manhattanFringe->calculateWeights();
			Node* manhatPath = manhattanFringe->findPath();
			manhattanFringe->printPath(manhatPath);
            cout<<"********************"<<endl;
		}


		if(runAll || specificRun == "3"){
    		cout << "Strategy 3: \n";
			GridMap *forAEuclid = p->parseFile(fileName);
			AEuclideanFringe *aEuclideanFringe = new AEuclideanFringe(forAEuclid);
			aEuclideanFringe->calculateWeights();
			Node* aEuclidPath = aEuclideanFringe->findPath();
			aEuclideanFringe->printPath(aEuclidPath);
            cout<<"********************"<<endl;
		}


		if(runAll || specificRun == "4"){
    		cout << "Strategy 4: \n";
			GridMap *forAManhat = p->parseFile(fileName);
			AManhattanFringe *aManhattanFringe = new AManhattanFringe(forAManhat);
			aManhattanFringe->calculateWeights();
			Node* aManhatPath = aManhattanFringe->findPath();
			aManhattanFringe->printPath(aManhatPath);
		}
	}
	catch(const char* exception){
		cout << "No path exists for file: " << fileName << endl;
	}





	return 0;
}