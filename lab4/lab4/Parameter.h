#pragma once
#include <string>

using namespace std;

class parameter

{

public:

	parameter(){}

	void set_sort_1(string t)
	{
		sort_1=t;
	}

	string get_sort_1()
	{
		return sort_1;
	}

private:

	string sort_1;



};
