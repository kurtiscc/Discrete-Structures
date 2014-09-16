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
#include "Graph.h"

using namespace std;

class Interpreter

{

public:

	Interpreter(){}

	~Interpreter(){}

	void begin(string filename, Datalog& t);

	void Facts(vector <predicate>& t);

	void Schemes(vector <predicate>& t);

	void Queries(vector <predicate>& t, vector <Rule> all_my_rules);

	Relation Queries_2(predicate t);

	void Parameter(vector <parameter> param_list, int index1, Relation& my_relation, vector <int>& t);

	void name_change(vector <int>& index, vector <parameter>& param, Relation& sweet_rel);

	void print_file(predicate& query, Relation my_relation);

	void Rules(vector <Rule> all_my_rules, bool redo_rules, vector <int>& eval_of_rules);

	ofstream outFile;

	void Unify(Relation to_add);

	vector <int> Attributes(predicate t, Scheme scheme);

private:

	Database DataBase; 

	Graph info;

};
