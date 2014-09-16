#pragma once

#include <vector>
#include <string>

#include "Predicate.h"

using namespace std;

class Rule

{

public:

	Rule(){}

	string to_string()
	{
		string temporary;

		temporary=temporary+pred_list[0].to_string()+" :- ";
		for(int i=1; i<pred_list.size();i++)
		{
			temporary=temporary+pred_list[i].to_string()+",";
		}
		temporary=temporary.substr(0, temporary.size()-1);
		
		return temporary;
	}	

	void clean()
	{
		pred_list.clear();
	}

vector<predicate> pred_list;

private:
	

};