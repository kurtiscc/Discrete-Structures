#pragma once

#include <vector>
#include <string>

#include "Tuple.h"
#include "Parameter.h"


using namespace std;

class predicate

{

public:

	predicate(){}

	string to_string();

	void set_id(string t);

	string get_id();

	void ADD(string t);

	void clear();

	string get_parameter(int index1);

	int get_size();

	Tuple to_tup();

	vector <parameter> get_vec();

private:

	string temp;

	vector <parameter>params_list;
	




};
