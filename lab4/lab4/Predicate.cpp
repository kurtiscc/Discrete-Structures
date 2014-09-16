#include "Predicate.h"


string predicate::to_string()
{
	string sneechaleech;

	sneechaleech = sneechaleech + temp + "(";

	for(int i = 0; i < params_list.size(); i++)
	{
		sneechaleech = sneechaleech + params_list[i].get_sort_1()+",";
	}

	sneechaleech = sneechaleech.substr(0,sneechaleech.size() - 1);

	sneechaleech = sneechaleech+")";

	return sneechaleech;
}

void predicate::set_id(string t)
{
	temp = t;
}

string predicate::get_id()
{
	return temp;
}

void predicate::ADD(string t)
{
	parameter temp;
    temp.set_sort_1(t);
    params_list.push_back(temp);
	
}

void predicate::clear()
{
	temp = "";
	params_list.clear();
}

string predicate::get_parameter(int index1)
{
	return params_list[index1].get_sort_1();
}

int predicate::get_size()
{
	return params_list.size();
}

Tuple predicate::to_tup()
{
	Tuple result;
	
	for (int i = 0 ; i < params_list.size(); i++)
		result.push_back(params_list[i].get_sort_1());

	return result;
}

vector <parameter> predicate::get_vec()
{
	return params_list;

}
