#include "Interpreter.h"

void Interpreter::begin(string filename, Datalog& t)
{
	outFile.open(filename.c_str());
	Schemes(t.scheme_list);
	Facts(t.facts_list);
	Rules(t.rules_list);
	Queries(t.queries_list);
	outFile << "Done!";


}
void Interpreter::Schemes(vector <predicate>& t)
{
	Relation temp;
	for(int i = 0; i < t.size(); i++)
	{
		Relation temp;
		temp.set_name(t[i].get_id());
		for(int b = 0; b < t[i].get_size(); b++)
		{
			temp.set_value(t[i].get_parameter(b));
		}
		DataBase.ADD(temp);
	}
}
void Interpreter::Facts(vector <predicate>& t)
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j<DataBase.database_vector.size(); j++)
			if (DataBase.database_vector[j].get_name() == t[i].get_id())
			{
				DataBase.database_vector[j].set_tuple(t[i].to_tup());
				break;
			}
	}
}
void Interpreter::Queries(vector <predicate>& t)
{
	for (int i = 0; i < t.size(); i++)
	{
		Relation temp = Queries_2(t[i]);
		print_file (t[i], temp);
	}
}

Relation Interpreter::Queries_2(predicate t)
{
	Relation temp;

	vector <int> indexParam;

	for (int j = 0; j < DataBase.database_vector.size(); j++)
	{
		if (t.get_id() == DataBase.database_vector[j].get_name())
		{
			temp = DataBase.database_vector[j];
			for (int x = 0; x < t.get_size(); x++)
				Parameter(t.get_vec(), x, temp, indexParam);
			temp = temp.project(indexParam);
			for (int z = 0; z < indexParam.size(); z++)
					temp = temp.name_change(t.get_vec()[indexParam[z]].get_sort_1(), z);
	        break;
		}
	}
	return temp;
}

void Interpreter::Parameter(vector <parameter> param_list, int index1, Relation& my_relation, vector <int>& t)
{
	Relation result;
	bool select = false;
	if (param_list[index1].get_sort_1().substr(0,1) == "'")
	{
		my_relation = my_relation.sel_2(index1, param_list[index1].get_sort_1());

		select = true;
	}
	else

		for (int i = 0; i < index1; i++)
		{
			if (param_list[i].get_sort_1() == param_list[index1].get_sort_1())
			{
				my_relation = my_relation.sel_1(i, index1);

				select = true;
			}			
		}

		if (!select)
			t.push_back(index1);

}

void Interpreter::print_file(predicate& query, Relation my_relation)
{
	outFile << query.to_string() << "? ";

	if (my_relation.get_size() == 0)
		outFile << "No" << endl;

	else
	{
		if (my_relation.empty(my_relation))
		{
			outFile << "Yes(1)" << endl;
		}
		else
		{
			outFile << "Yes(" << my_relation.get_size() << ")" <<endl << my_relation.to_string();	
		}
	}

}

void Interpreter::Rules(vector <Rule> allRules)
{
	Relation my_result_1;

	Relation my_result_2;

	bool redo = true;

	int db_size = DataBase.size();

	int num_passed = 0;
	
	while (redo)
	{
		for(int i = 0; i < allRules.size(); i++)
		{
			if (allRules[i].pred_list.size() > 1)
				my_result_1 = Queries_2(allRules[i].pred_list[1]);

			for (int j = 2; j < allRules[i].pred_list.size(); j++)
			{
				my_result_2 = Queries_2(allRules[i].pred_list[j]);
				my_result_1 = my_result_1.combinator(my_result_2);
			}

			vector <int>  vect = Attributes(allRules[i].pred_list[0], my_result_1.get_scheme());

			my_result_1 = my_result_1.project(vect);

			my_result_1.set_name((allRules[i]).pred_list[0].get_id());

			Unify(my_result_1);
		}

		num_passed++;
		redo = (db_size < DataBase.size());
		db_size = DataBase.size();
	}

	outFile << "Schemes populated after " << num_passed << " passes through the Rules.\n";
}

vector <int> Interpreter::Attributes(predicate t, Scheme scheme)
{
	vector <int> result;

	vector <parameter> temp = t.get_vec();

	for (int x = 0; x < temp.size(); x++)

		for (int i = 0; i < scheme.size(); i++)

			if (scheme.at(i) == temp[x].get_sort_1())

				if (find(result.begin(), result.end(), i) == result.end()) 

					result.push_back(i);
	return result;
}

void Interpreter::Unify(Relation to_add)
{
	for (int j = 0; j < DataBase.database_vector.size(); j++)
	{

		if (to_add.get_name() == DataBase.database_vector[j].get_name())	
		{

			if (to_add.get_scheme().size() == DataBase.database_vector[j].get_scheme().size())
			{

				for (int i = 0; i < to_add.get_size(); i++)

					DataBase.database_vector[j].set_tuple(to_add.get_tup(i));
			}

			break;
		}
	}
}
