#pragma once


#include <iostream>

#include <vector>

#include "Relation.h"

using namespace std;

class Database

{

public:

	Database(){}

	~Database(){}

	void ADD(Relation relate)
	{
		database_vector.push_back(relate);
	}
	
	vector<Relation> database_vector;

	int size()
	{
		int temp = 0;

		for (int i = 0; i < database_vector.size(); i++)

		temp = temp + database_vector[i].get_size();

		return temp;
	}


private:
	
};