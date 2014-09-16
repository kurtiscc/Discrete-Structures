#include "parser.h"


DP parser::start(vector<string>t, string filenameOut)
{
	ofstream outFile;

	outFile.open(filenameOut.c_str());

	list=t;
	if(t.size()>0)
	{
		token = 0;
		try 
		{
			dataLog();
		}
		catch(int i)
		{

			outFile<<"Failure!"<<endl<<"  "<<t[token];
		}
		catch(const char* f)
			{
				

				myObject.queries_list.push_back(currentPredicate);
				currentPredicate.clear();
		outFile<<myObject.toString();
			}
		
	}

		
	return myObject;
}
void parser::match(string t)
{

		if(list[token].substr(1,t.size())==t)
		{
			if(list.size()-1==token)
			{
			if (list[token].substr(1,1)=="Q")
			throw "end";
			else
			throw token;
		}
		else
			token++;
		}
		else throw token;
	
}
void parser::dataLog()
{
	match("SCHEMES");
	match("COLON");
	schemeList();
	match("FACTS");
	match("COLON");
	factList();
	match("RULES");
	match("COLON");
	ruleList();
	match("QUERIES");
	match("COLON");
	queryList();

	if(token<=list.size()-1)
		throw token;

}
void parser::schemeList()
{
	scheme();
	myObject.scheme_list.push_back(currentPredicate); 
	currentPredicate.clear();
	if(list[token].substr(1,2)=="ID")
		schemeList();

}
void parser::scheme()
{
	pred();
}
void parser::factList()
{
	if(list[token].substr(1,2)=="ID")
	{
		fact();
		myObject.facts_list.push_back(currentPredicate);
		currentPredicate.clear();
		factList();
	}

}
void parser::fact()
{
	pred();
	match("PERIOD");
}
void parser::ruleList()
{
	if(list[token].substr(1,2)=="ID")
	{
		rule();

		myObject.rules_list.push_back(currentRule);
		currentRule.clean();
		
			ruleList();
	}
}
void parser::rule()	 
{
	pred();
	currentRule.listOfPredicate.push_back(currentPredicate);
	currentPredicate.clear();
	match("COLON_DASH");
	predicateList();
	match("PERIOD");
}
void parser::queryList()  
{

		query();


			myObject.queries_list.push_back(currentPredicate);
			currentPredicate.clear();
			if(list[token].substr(1,2)=="ID")
			{
				queryList();

			}

}
void parser::query()
{
	pred();
	match("Q_MARK");
}
void parser::predicateList()
{
	pred();
	currentRule.listOfPredicate.push_back(currentPredicate);
	currentPredicate.clear();
	if(list[token].substr(1,5)=="COMMA")
	{
		match("COMMA");
		predicateList();
	}
}
void parser::pred()
{
	currentPredicate.setID(returnValue(list[token]));
	match("ID");
	match("LEFT_PAREN");
	parameterList();
	match("RIGHT_PAREN");
}
void parser::parameterList()
{
	param();
	if(list[token].substr(1,5)=="COMMA")
	{
		match("COMMA");
		parameterList();
	}
}
void parser::param()
{
	if(list[token].substr(1,6)=="STRING")
	{
		string temp;
		temp=temp+"'"+returnValue(list[token])+"'";
		currentPredicate.add(temp);
		if(!myObject.inDomain(temp))
		{
			myObject.domain.push_back(temp);
		}
		match("STRING");
	}
	else if(list[token].substr(1,2)=="ID")
	{
		currentPredicate.add(returnValue(list[token]));
		match("ID");

	}
	else
		throw token;
}
string parser::returnValue(string t)
{	
	string result;
	char temp;
	bool sneechaleech = false;
	for(int i=0; i<t.size(); i++)
	{

		if(sneechaleech)
		{
			result=result+t[i];
		}
		if(t[i]=='"')
		{
			sneechaleech=!sneechaleech;
		}
	}
	result=result.substr(0,result.size()-1);
	return result;
}
