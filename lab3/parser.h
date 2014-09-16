#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "DP.h"

using namespace std;

class parser
{
public:
	parser()
	{	}
	DP start(vector <string> t, string filenameOut);

private:
	int token;
	vector<string>list;
	void dataLog();
	void schemeList();
	void scheme();
	void factList();
	void fact();
	void ruleList();
	void rule();
	void queryList();
	void query();
	void predicateList();
	void pred();
	void parameterList();
	void param();
	void match(string t);
	string returnValue(string t);
	DP myObject;
	predicate currentPredicate;
	Rule currentRule;



};
