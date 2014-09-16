#pragma once


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Scheme

{

public:

	Scheme(){}

	~Scheme(){}

	string at(int index1)
	{
		return attributes[index1];
	}

	string scheme_string(int index1)
	{

		return attributes[index1];

	}	

	int ADD(string my_name)
	{
		int temp;
		bool has = false;
		for (int i = 0; i < attributes.size(); i++)
			if (attributes[i]==my_name)
			{
				temp = i;
				has = true;
				break;
			}
		if (!has)
		{
			attributes.push_back(my_name);
			temp=-1;
		}
		return temp;
	}

	void name_change(int index1, string& my_name)
	{

		attributes[index1]=my_name;
	}
	
	int size()
	{
		return attributes.size();
	}
	
	Scheme combine_schemes(Scheme right, vector <pair<int,int> >& t)
	{
		Scheme temp(*this);

		int j;

		for (int i = 0; i < right.size(); i++)
		{
			j = temp.ADD(right.at(i));

			if (j != -1)
				t.push_back(pair<int,int> (j,i));
		}
		
		return temp;
	}

private:

	vector<string> attributes;


};