#pragma once
#include <string>
#include <vector>
#include "Parameter.h"
#include "tupley.h"

using namespace std;

class predicate
{
public:
	predicate(){}
	string toString();
	void setID(string t);
	string getID();
	void add(string t);
	void clear();
	string getParam(int kurt1);
	int getSize();
	Tuple toTuple();
	vector <parameter> getVector();

private:
	string temp;
	vector <parameter>param_list;
	




};
