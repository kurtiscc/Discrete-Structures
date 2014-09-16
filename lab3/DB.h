#pragma once
#include <vector>
#include <iostream>
#include "relatey.h"

using namespace std;

class database
{
public:
	database(){}
	~database(){}
	void add(Relation r);
	vector<Relation>DB_vec;
private:
	

};