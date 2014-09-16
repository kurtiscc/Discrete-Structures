#pragma once
#include <vector>
#include <string>
#include "relatey.h"
#include "DB.h"
#include "DP.h"
#include "Predicate.h"
#include <istream>
#include <sstream>
#include <fstream>

using namespace std;

class interpreter
{
public:
	interpreter(){}
	~interpreter(){}

	void start(string filename, DP& t);
	void Facts(vector <predicate>& t);
	void Schemes(vector <predicate>& t);
	void Queries(vector <predicate>& t);
	void Parameter(vector <parameter> parameterList, int kurt1, Relation& relatey, vector <int>& t);
	void rename(vector <int>& index, vector <parameter>& param, Relation& rel);
	void printToFile(predicate& query, Relation relatey);
	ofstream outFile;

private:
	database DataBase; 

};
