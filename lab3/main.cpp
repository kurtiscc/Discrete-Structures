#include <iostream>
#include <string>
#include "scanner.h"
#include "parser.h"
#include "interpreter.h"

using namespace std;

int main(int argc, const char * argv[])
{

	ifstream inFile(argv[1]);
	ofstream outFile ("out.txt");
	
	scanner Kurt;
	vector<string>tokenator;
	tokenator= Kurt.readFile(inFile, outFile);
	parser Des;
	DP sneech;

	sneech=Des.start(tokenator, "out.txt"); 

	interpreter sneecher;
	sneecher.start(argv[2], sneech);

	inFile.close();
	outFile.close();
	
	
    return 0;
}
