#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class scanner
{
public:
	scanner();

	vector <string> readFile(ifstream& inFile, ofstream& outFile);
	void readID(char t, ifstream& inFile, ofstream& outFile);
	void readChar(ifstream& inFile, char t, ofstream& outFile);
	void processString(ifstream& inFile, ofstream& outFile);
	void processID(string ID, ofstream& outFile);

private:
	int lineCount;
	int tokenCount;
	bool anya;
	vector<string>tokens;



};
