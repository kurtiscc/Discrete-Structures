#pragma once
#include <set>
#include "tupley.h"
#include "schemy.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Relation
{
public:

	Relation(){}
	~Relation(){}

	Relation select1(int kurt1, int kurt2);
	Relation select2(int kurt1, string value);
	Relation project(vector<int>& kurt1);
	Relation rename(string newName, int kurt1);
	string getName();
	int getSize();
	bool empty(Relation temp);
	void setName(string newName);
	void setValue(string newValue);
	void setTuple(Tuple t);
	string toString();

private:
	set <Tuple> setOfTuples;
	string name;
	Scheme values;

};