#pragma once

#include <sstream>
#include <set>

#include <string>
#include <vector>

#include "Tuple.h"
#include "Scheme.h"


using namespace std;

class Relation

{

public:

	 Relation(){}

	~Relation(){}

	Relation sel_1(int index1, int index2);

	Relation sel_2(int index1, string value);

	Relation project(vector<int>& index1);

	Relation name_change(string new_name, int index1);

	string get_name();
	
	bool empty(Relation temp);

	void set_tuple(Tuple t);

	void set_name(string new_name);

	void set_value(string new_value);

	int get_size();

	string to_string();

	Scheme get_scheme();

	Tuple get_tup(int index);
	
	Relation combinator(Relation& right);

private:

	set <Tuple> Tuple_Set;

	string my_name;
	
	Scheme my_values;

};