#pragma once

#include <sstream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>

#include "Datalog.h"
#include "Predicate.h"
#include "Relation.h"
#include "Database.h"

using namespace std;

class Interpreter

{

public:

	Interpreter(){}

	~Interpreter(){}

	void begin(string filename, Datalog& t);

	void Facts(vector <predicate>& t);

	void Schemes(vector <predicate>& t);

	void Queries(vector <predicate>& t);

	Relation Queries_2(predicate t);

	void Parameter(vector <parameter> param_list, int index1, Relation& my_relation, vector <int>& t);

	void name_change(vector <int>& index, vector <parameter>& param, Relation& rel);

	void print_file(predicate& query, Relation my_relation);

	void Rules(vector <Rule> allRules);

	ofstream outFile;

	void Unify(Relation to_add);

	vector <int> Attributes(predicate t, Scheme scheme);

private:

	Database DataBase; 

};
