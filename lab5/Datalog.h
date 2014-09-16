#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include "Rule.h"
#include "Predicate.h"


using namespace std;

class Datalog

{

public:

	Datalog(){}
	
	bool universe_exists(string t)
	{
		bool temp = true;

		for(int i = 0; i < universe.size(); i++)
		{
			if(universe[i] == t)
			
			return temp;
		}

		return !temp;
	}

	vector<predicate> scheme_list;

	vector<predicate> facts_list;

	vector<predicate> queries_list;

	vector<Rule> rules_list;

	vector<string> universe;
	
	bool in_domain(string t)
	{
		bool temp = false;

		for (int i = 0; i < universe.size(); i++)
		
		if (universe[i] == t)
		{
			temp = true;

			break;
		}

		return temp;
	}

	string to_string()
	{

		string temp;

		ostringstream list;

		list << "Success!\n";

		list << "Schemes(" << scheme_list.size() << "):\n";

		for(int i = 0; i < scheme_list.size(); i++)

			list << "  " << scheme_list[i].to_string() << endl;

		list << "Facts(" << facts_list.size() << "):\n";

		for(int i = 0; i < facts_list.size(); i++)

			list << "  " << facts_list[i].to_string() << endl;

		list << "Rules(" << rules_list.size() << "):\n";

		for(int i = 0; i < rules_list.size(); i++)

			list << "  " << rules_list[i].to_string() << endl;

		list << "Queries(" << queries_list.size() << "):\n";

		for(int i = 0; i < queries_list.size(); i++)

			list << "  " << queries_list[i].to_string() << endl;

		list << "Domain(" << universe.size() << "):\n";

		sort(universe.begin(),universe.end());

		for(int i = 0; i < universe.size(); i++)

			list << "  " << universe[i] << endl;

		temp = list.str();

		return temp;
	}
	
};