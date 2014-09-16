#include <iostream>
#include <string>
#include <fstream>
#include "Lexical_Analyzer.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream inFile;
	ofstream outFile;
	
	inFile.open(argv[1]);
	outFile.open(argv[2]);

	Lexical_Analyzer lex_an;
	string input;

	
	//while(inFile >> input)
	//{
		lex_an.find_token(inFile, outFile);
	//}



}
