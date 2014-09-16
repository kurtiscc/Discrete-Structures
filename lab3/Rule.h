#pragma once
#include <string>
#include <vector>
#include "Predicate.h"

using namespace std;

class Rule
{
public:
	Rule(){}
	string toString();
	void clean();
vector<predicate> listOfPredicate;
private:
	

};