#include <string>
#include <iostream>

#include "Parser.h"
#include "Interpreter.h"
#include "Scanner.h"

using namespace std;

int main(int argc, const char * argv[])
{

	ifstream inFile(argv[1]);

	ofstream outFile ("out.txt");
	
	Scanner Scan;

	vector<string> kurts_tokens;

	kurts_tokens = Scan.readFile(inFile, outFile);

	Parser Parse;

	Datalog Kurts_Datalog;

	Kurts_Datalog = Parse.begin(kurts_tokens, "out.txt"); 

	Interpreter Interpret;

	Interpret.begin(argv[2], Kurts_Datalog);

	inFile.close();

	outFile.close();

    return 0;
}
