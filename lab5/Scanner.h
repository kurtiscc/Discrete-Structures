#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Scanner

{
	
public:

	Scanner();

	vector <string> readFile(ifstream& inFile, ofstream& outFile);

	void readID(char t, ifstream& inFile, ofstream& outFile);

	void readChar(ifstream& inFile, char t, ofstream& outFile);

	void processString(ifstream& inFile, ofstream& outFile);

	void processID(string ID, ofstream& outFile);

private:

	int line_counter;

	int tok_counter;

	bool desirae;

	vector<string> tokenator;



};
