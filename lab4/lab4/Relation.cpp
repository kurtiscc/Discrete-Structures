#include "Relation.h"


Relation Relation::sel_1(int index1, int index2)
{
	Relation temp;
	for (set<Tuple>::iterator it = Tuple_Set.begin(); it != Tuple_Set.end(); ++it)
	{
		if((*it)[index1] == (*it)[index2])
		{
			temp.Tuple_Set.insert(*it);

		}

	}

	temp.my_name = my_name;
	temp.my_values = my_values;
	return temp;
}

Relation Relation::sel_2(int index1, string value)
{
	Relation temp;
	for (set<Tuple>::iterator it = Tuple_Set.begin(); it != Tuple_Set.end(); ++it)
	{
		if((*it)[index1] == value)
		{
			temp.Tuple_Set.insert(*it);
		}
	}

	temp.my_name = my_name;

	temp.my_values = my_values;
	return temp;
}
Relation Relation::project(vector<int>& index1)
{
	Relation temp;

	Tuple tempTuplele;

	for(int i=0; i<index1.size(); i++)
	{
		temp.my_values.ADD(my_values.scheme_string(index1[i]));
	}

	for (set<Tuple>::iterator it = Tuple_Set.begin(); it != Tuple_Set.end(); ++it)
	{
		for(int i = 0; i < index1.size(); i++)
		{
			tempTuplele.push_back((*it)[index1[i]]);
		}

		temp.Tuple_Set.insert(tempTuplele);
		tempTuplele.clear();
	}

	temp.my_name = my_name;

	return temp;
}

Relation Relation::name_change(string new_name, int index1)
{
	Relation temp = *this;

	temp.my_values.name_change(index1, new_name);

	return temp;
}

string Relation::get_name()
{
	return my_name;
}

int Relation::get_size()
{
	return Tuple_Set.size();
}

bool Relation::empty(Relation temp)
{
	if(temp.my_values.size() == 0)
		return true;
	return false;
}

void Relation::set_name(string new_name)
{
	my_name = new_name;
}

void Relation::set_value(string new_value)
{
	my_values.ADD(new_value);
}

string Relation::to_string()
{
	ostringstream streamify;

	for (set<Tuple>::iterator it = Tuple_Set.begin(); it != Tuple_Set.end(); ++it)
	{
		streamify << "  ";

		for (int i = 0; i < (*it).size() - 1; i++)
			streamify << my_values.scheme_string(i) << "=" << (*it)[i] << ", ";

		streamify << my_values.scheme_string((*it).size()-1)<<"=" << (*it)[(*it).size() - 1] << endl;
	} 
	return streamify.str();
}
void Relation::set_tuple(Tuple t)
{
	Tuple_Set.insert(t);
}

Scheme Relation::get_scheme()
{
	return my_values;
}

Tuple Relation::get_tup(int index)
{
	set<Tuple>::iterator it = Tuple_Set.begin();

	for (int i = 0; i < index; i++)
		++it;

	return *it;
}

Relation Relation::combinator(Relation& right)
{
	Scheme temp;

	vector <pair<int,int> > at_relation;

	temp = my_values.combine_schemes(right.my_values, at_relation);

	Relation result; 

	for (int i = 0; i < temp.size(); i++)

		result.set_value(temp.at(i));

	for (set<Tuple>::iterator it = Tuple_Set.begin(); it != Tuple_Set.end(); ++it)

		for (set<Tuple>::iterator it2 = right.Tuple_Set.begin(); it2 != right.Tuple_Set.end(); ++it2)
		{
			Tuple t(*it);

			if (t.joinable((*it2), at_relation))
			{
				t = t.combinator((*it2), at_relation);

				result.set_tuple(t);
			}
		}
			return result;
}