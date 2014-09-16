#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include "Token.h"
#include <sstream>
#include "Parameter.h"
#include <fstream>

using namespace std;

class Parser
{
private:
	vector<Token> TokenList;
	set<string> universeList;
	queue<Token> schemes;
	queue<Token> facts;
	queue<Token> rules;
	queue<Token> queries;
	queue<string> finishedList;


public:
	Parser(vector<Token> token_list_in)
	{
		TokenList=token_list_in;
	}
	virtual ~Parser(){}

	void parse();
	void allot();
	void checkScheme();
	void checkFacts();
	void checkRules();
	void checkQueries();
	string getSchemes();
	string getID(int input, queue<Token>& Char);
	string getColon(queue<Token>& Char);
	string getLParen(int input, queue<Token>& Char);
	string getComma(int input, queue<Token>& Char);
	string getRParen(int input, queue<Token>& Char);
	string getFacts();
	string getPeriod(int input, queue<Token>& Char);
	string getString(int input, queue<Token>& Char);
	string getRules();
	string getColonDash(int input, queue<Token>& Char);
	string getQMark(int input, queue<Token>& Char);
	string getQueries();
	Token getError();
	void outToFile(ofstream& outFile);
	void checkIfNone(queue<Token>& Char);
};