#include "relatey.h"


Relation Relation::select1(int kurt1, int kurt2)
{
	Relation temp;
	for (set<Tuple>::iterator it=setOfTuples.begin(); it!=setOfTuples.end(); ++it)
	{
		if((*it)[kurt1]==(*it)[kurt2])
		{
			temp.setOfTuples.insert(*it);

		}

	}
	temp.name=name;
	temp.values=values;
	return temp;
}

Relation Relation::select2(int kurt1, string value)
{
	Relation temp;
	for (set<Tuple>::iterator it=setOfTuples.begin(); it!=setOfTuples.end(); ++it)
	{
		if((*it)[kurt1]==value)
		{
			temp.setOfTuples.insert(*it);
		}
	}
	temp.name=name;
	temp.values=values;
	return temp;
}
Relation Relation::project(vector<int>& kurt1)
{
	Relation temp;
	Tuple tempTuple;
	for(int i=0; i<kurt1.size(); i++)
	{
		temp.values.add(values.at(kurt1[i]));
	}
	for (set<Tuple>::iterator it=setOfTuples.begin(); it!=setOfTuples.end(); ++it)
	{
		for(int i=0; i<kurt1.size(); i++)
		{
			tempTuple.push_back((*it)[kurt1[i]]);
		}
		temp.setOfTuples.insert(tempTuple);
		tempTuple.clear();
	}
	temp.name=name;
	return temp;
}

Relation Relation::rename(string newName, int kurt1)
{
	Relation temp=*this;
	temp.values.rename(kurt1, newName);
	return temp;
}

string Relation::getName()
{
	return name;
}

int Relation::getSize()
{
	return setOfTuples.size();
}
bool Relation::empty(Relation temp)
{
	if(temp.values.size()==0)
		return true;
	return false;
}
void Relation::setName(string newName)
{
	name=newName;
}
void Relation::setValue(string newValue)
{
	values.add(newValue);
}
string Relation::toString()
{
	ostringstream strm;
	for (set<Tuple>::iterator it=setOfTuples.begin(); it!=setOfTuples.end(); ++it)
	{
		strm<<"  ";
		for (int i=0; i<(*it).size()-1; i++)
			strm<<values.at(i)<<"="<<(*it)[i]<<", ";
		strm<<values.at((*it).size()-1)<<"="<<(*it)[(*it).size()-1]<<endl;
	}
	return strm.str();
}
void Relation::setTuple(Tuple t)
{
	setOfTuples.insert(t);
}