#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Predicate.h"
#include "Rule.h"

using namespace std;

class DP
{
public:
	DP(){}
	string toString();
	bool universe_exists(string t);

	vector<predicate>scheme_list;
	vector<predicate>facts_list;
	vector<predicate>queries_list;
	vector<Rule>rules_list;
	vector<string>domain;
	bool inDomain(string t);
	
};