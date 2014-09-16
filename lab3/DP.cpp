#include "DP.h"

string DP::toString()
{
	string temp;
	ostringstream list;
	list<<"Success!\n";
	list<<"Schemes("<<scheme_list.size()<<"):\n";

	for(int i=0;i<scheme_list.size();i++)
		list<<"  "<<scheme_list[i].toString()<<endl;

	list<<"Facts("<<facts_list.size()<<"):\n";
	for(int i=0;i<facts_list.size();i++)
		list<<"  "<<facts_list[i].toString()<<endl;

	list<<"Rules("<<rules_list.size()<<"):\n";
	for(int i=0;i<rules_list.size();i++)
		list<<"  "<<rules_list[i].toString()<<endl;

	list<<"Queries("<<queries_list.size()<<"):\n";
	for(int i=0;i<queries_list.size();i++)
		list<<"  "<<queries_list[i].toString()<<endl;

	list<<"Domain("<<domain.size()<<"):\n";
	sort(domain.begin(),domain.end());
	for(int i=0;i<domain.size();i++)
		list<<"  "<<domain[i]<<endl;


	temp=list.str();
	return temp;
}
bool DP::universe_exists(string t)
{
	bool temp=true;
	for(int i=0; i<domain.size();i++)
	{
		if(domain[i]==t)
			return temp;
	}
	return !temp;
}
bool DP::inDomain(string t)
{
	bool temp=false;
	for (int i=0; i<domain.size(); i++)
		if (domain[i]==t)
		{
			temp=true;
			break;
		}
	return temp;
}

