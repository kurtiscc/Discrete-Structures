#include "Rule.h"


string Rule::toString()
{
	string temp;

	temp=temp+listOfPredicate[0].toString()+" :- ";
	for(int i=1; i<listOfPredicate.size();i++)
	{
		temp=temp+listOfPredicate[i].toString()+",";
	}
	temp=temp.substr(0, temp.size()-1);
	
	return temp;
}
void Rule::clean()
{
	listOfPredicate.clear();
}