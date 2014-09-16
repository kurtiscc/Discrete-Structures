#include "Token.h"
#include "Parameter.h"
#include <string>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

class Predicate
{
private:
	
public:
	Predicate(){};
	virtual ~Predicate(){};
	string varify(queue<Token>& Char)
	{
		queue<string> temp;
		stringstream ss;
		string kurt;
		string counter;
		int count=0;
		int input;
		Parameter freshParam;
		temp.push(getSchemes());
		input=schemes.front().fetchLineNum();
		kurt="  ";

		kurt+=getID(input, schemes);
		kurt+=getLParen(input, schemes);
		kurt+=freshParam.fectchParam(input,schemes);
		kurt+=getRParen(input, schemes);

		count++;
		temp.push(kurt);
	}
};
	