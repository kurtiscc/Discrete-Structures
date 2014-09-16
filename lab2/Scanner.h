#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <fstream>
#include <vector>
#include "Token.h"

using namespace std;

class Scanner
{
	private:
		int lineCounter;
		map<string, string> tokenInput;
		queue<string> finishedList;
		queue<string> error;
		bool inInput;
		bool errorFind;
		bool comment;

	public:
		Scanner()
		{
			lineCounter=1;
			tokenInput.insert(make_pair(",", "COMMA"));
			tokenInput.insert(make_pair(".", "PERIOD"));
			tokenInput.insert(make_pair("?", "Q_MARK"));
			tokenInput.insert(make_pair("(", "LEFT_PAREN"));
			tokenInput.insert(make_pair(")", "RIGHT_PAREN"));
			tokenInput.insert(make_pair(":", "COLON"));
			tokenInput.insert(make_pair(":-", "COLON_DASH"));
			tokenInput.insert(make_pair("Schemes", "SCHEMES"));
			tokenInput.insert(make_pair("Facts", "FACTS"));
			tokenInput.insert(make_pair("Rules", "RULES"));
			tokenInput.insert(make_pair("Queries", "QUERIES"));
			inInput=false;
			comment=false;
			errorFind=false;
		}
		~Scanner(){};
		bool identifier(string input);
		string verifyChar(string character);
		string checkPunc(string character);
		void stringer();
		string option1(string input, string output, string result);
		string option2(string input, string output, string result, queue<string>&listOfChars);
		string option3(string input, string output, string result, queue<string>&listOfChars);
		bool validate(string output);
		void initiateError(ofstream &outFile);
		int write(ofstream &outFile);
		queue<string> toWords(stringstream &ss);
		queue<string> toChar(queue<string> &listOfWords, string &output);
		bool parse(queue<string> &listOfChars, string &output);
		vector<Token> tokenify();
};