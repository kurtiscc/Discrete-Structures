#pragma once

#include <string>
#include <vector>


using namespace std;


class Tuple:public vector <string>

{

public:

	Tuple(){}
	
	~Tuple(){}

	bool joinable(Tuple right, vector <pair<int,int> >& temp)
	{
	   	for (int i = 0; i < temp.size(); i++)

		if ((*this)[temp[i].first] != right[temp[i].second])
			  return false;
	   	return true;
	}

	Tuple combinator(Tuple right, vector <pair<int,int> >& temp)
	{
		for (int i = 0; i < right.size(); i++)
		{
			bool duplicate = false;
			for (int j = 0; j < temp.size(); j++)
				if (temp[j].second == i)
				{
					duplicate = true;
					break;
				}
			if (!duplicate)
				(*this).push_back(right[i]);
		}
	    return *this;
	}


};