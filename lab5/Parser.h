#pragma once

#include <sstream>
#include <fstream>


#include <string>
#include <iostream>
#include <vector>

#include "Datalog.h"

using namespace std;

class Parser

{

public:
	
	Parser(){}

	Datalog begin(vector <string> t, string out_file_name);

private:

	int token;

	vector<string>list;

	void dataLog();

	void scheme_list();

	void Scheme();

	void fact_list();

	void fact();

	void rule_list();

	void rule();

	void query_list();

	void query();

	void pred_list();

	void predicator();

	void param_list();

	void param();

	void match_up(string t);

	string return_val(string t);

	Datalog my_obj;

	predicate curr_pred;

	Rule curr_rule;



};
