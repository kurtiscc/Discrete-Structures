#include "Predicate.h"


string predicate::toString()
{
	string loshara;
	loshara=loshara+temp+"(";
	for(int i=0; i<param_list.size(); i++)
	{
		loshara = loshara + param_list[i].getSorI()+",";
	}
	loshara=loshara.substr(0,loshara.size()-1);
	loshara=loshara+")";
	return loshara;
}
void predicate::setID(string t)
{
	temp=t;
}
string predicate::getID()
{
	return temp;
}
void predicate::add(string t)
{
	parameter temp;
    temp.setSorI(t);
    param_list.push_back(temp);
	
}
void predicate::clear()
{
	temp="";
	param_list.clear();
}
string predicate::getParam(int kurt1)
{
	return param_list[kurt1].getSorI();
}
int predicate::getSize()
{
	return param_list.size();
}

Tuple predicate::toTuple()
{
Tuple result;
	for (int i=0; i<param_list.size(); i++)
		result.push_back(param_list[i].getSorI());
	return result;
}
vector <parameter> predicate::getVector()
{
	return param_list;

}
