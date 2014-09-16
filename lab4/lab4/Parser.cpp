#include "Parser.h"


Datalog Parser::begin(vector<string>t, string out_file_name)
{
	ofstream outFile;

	outFile.open(out_file_name.c_str());

	list = t;

	if(t.size() > 0)
	{
		token = 0;

		try 
		{
			dataLog();
		}

		catch(int i)
		{

			outFile << "Failure!" << endl << "  " << t[token];
		}

		catch(const char* f)
			{
				my_obj.queries_list.push_back(curr_pred);
				curr_pred.clear();
				outFile<<my_obj.to_string();
			}
		
	}

		
	return my_obj;
}
void Parser::match_up(string t)
{

		if(list[token].substr(1,t.size()) == t)
		{
			if(list.size()-1 == token)
			{
			if (list[token].substr(1,1) == "Q")
			throw "end";
			else
			throw token;
		}
		else
			token++;
		}
		else throw token;
	
}
void Parser::dataLog()
{
	match_up("SchemeES");
	match_up("COLON");
	scheme_list();
	match_up("FACTS");
	match_up("COLON");
	fact_list();
	match_up("RULES");
	match_up("COLON");
	rule_list();
	match_up("QUERIES");
	match_up("COLON");
	query_list();

	if(token <= list.size()-1)
		throw token;

}
void Parser::scheme_list()
{
	Scheme();
	my_obj.scheme_list.push_back(curr_pred);
	curr_pred.clear();
	if(list[token].substr(1,2) == "ID")
		scheme_list();

}
void Parser::Scheme()
{
	predicator();
}
void Parser::fact_list()
{
	if(list[token].substr(1,2) == "ID")
	{
		fact();
		my_obj.facts_list.push_back(curr_pred);
		curr_pred.clear();
		fact_list();
	}

}
void Parser::fact()
{
	predicator();
	match_up("PERIOD");
}
void Parser::rule_list()
{
	if(list[token].substr(1,2) == "ID")
	{
		rule();

		my_obj.rules_list.push_back(curr_rule);
		curr_rule.clean();
		
			rule_list();
	}
}
void Parser::rule()	 
{
	predicator();
	curr_rule.pred_list.push_back(curr_pred);
	curr_pred.clear();
	match_up("COLON_DASH");
	pred_list();
	match_up("PERIOD");
}
void Parser::query_list()  
{

		query();


			my_obj.queries_list.push_back(curr_pred);
			curr_pred.clear();
			if(list[token].substr(1,2) == "ID")
			{
				query_list();

			}

}
void Parser::query()
{
	predicator();
	match_up("Q_MARK");
}
void Parser::pred_list()
{
	predicator();
	curr_rule.pred_list.push_back(curr_pred);
	curr_pred.clear();
	if(list[token].substr(1,5) == "COMMA")
	{
		match_up("COMMA");
		pred_list();
	}
}
void Parser::predicator()
{
	curr_pred.set_id(return_val(list[token]));
	match_up("ID");
	match_up("LEFT_PAREN");
	param_list();
	match_up("RIGHT_PAREN");
}
void Parser::param_list()
{
	param();
	if(list[token].substr(1,5)=="COMMA")
	{
		match_up("COMMA");
		param_list();
	}
}
void Parser::param()
{
	if(list[token].substr(1,6)=="STRING")
	{
		string temp;
		temp = temp + "'" + return_val(list[token]) + "'";
		curr_pred.ADD(temp);

		if(!my_obj.in_domain(temp))
		{
			my_obj.universe.push_back(temp);
		}
		
		match_up("STRING");
	}
	else if(list[token].substr(1,2) == "ID")
	{
		curr_pred.ADD(return_val(list[token]));
		match_up("ID");

	}
	else
		throw token;
}
string Parser::return_val(string t)
{	
	string result;

	char temp;

	bool Scan = false;

	for(int i = 0; i < t.size(); i++)
	{

		if(Scan)
		{
			result = result + t[i];
		}

		if(t[i] == '"')
		{
			Scan =! Scan;
		}
	}

	result = result.substr(0,result.size() - 1);

	return result;
}
