#include "Parser.h"

void Parser::parse()
{
	allot();
	checkScheme();
	checkFacts();
	checkRules();
	checkQueries();
}

void Parser::allot()
{
	int i=0;

		while(i<TokenList.size()&&TokenList[i].getChar()!="FACTS")
		{
			schemes.push(TokenList[i]);
			i++;
		}
		while(i<TokenList.size()&&TokenList[i].getChar()!="RULES")
		{
			facts.push(TokenList[i]);
			i++;
		}
		while(i<TokenList.size()&&TokenList[i].getChar()!="QUERIES")
		{
			rules.push(TokenList[i]);
			i++;
		}
		while (i<TokenList.size())
		{
			queries.push(TokenList[i]);
			i++;
		}
	return;
}

void Parser::checkScheme()
{
	queue<string> temp;
	stringstream ss;
	string kurt;
	string counter;
	int count=0;
	int input;
	Parameter freshParam;
	temp.push(getSchemes());
	checkIfNone(schemes);
	while(schemes.size()!=0)
	{
		input=schemes.front().fetchLineNum();
		kurt="  ";
		kurt+=getID(input, schemes);
		kurt+=getLParen(input, schemes);
		kurt+=freshParam.fectchParam(input,schemes);
		kurt+=getRParen(input, schemes);
		count++;
		temp.push(kurt);
	}
	ss << "Schemes" << "(" << count << ")" << ":";
	ss >> counter;

	temp.pop();
	finishedList.push(counter);
	while(temp.size()!=0)
	{
		finishedList.push(temp.front());
		temp.pop();
	}
}

string Parser::getSchemes()
{
	checkIfNone(schemes);
	string temp;
	if(schemes.front().getChar()=="SCHEMES")
	{
		temp=schemes.front().getInfo();
		schemes.pop();
	}
	else
	{
		string des="error";
		throw des;
	}

	return temp+=getColon(schemes);	
}

string Parser::getColon(queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="COLON")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}
	else
	{
		string des="error";
		throw des;
	}

	return temp;
}

string Parser::getID(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;
	if(Char.front().getChar()=="ID")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}
	else
	{
		string des ="error";
		throw des;
	}

	return temp;
}

string Parser::getLParen(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="LEFT_PAREN")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}

	else
	{
		string des="error";
		throw des;
	}

	return temp;
}

string Parser::getRParen(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="RIGHT_PAREN")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}

	else
	{
		string des="error";
		throw des;
	}

	return temp;
}

string Parser::getComma(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="COMMA")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}

	else
	{
		string des="error";
		throw des;
	}

	return temp;
}

string Parser::getString(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="STRING")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}

	else
	{
		string des="error";
		throw des;
	}

	return temp;
}

string Parser::getPeriod(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="PERIOD")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}

	else
	{
		string des="error";
		throw des;
	}

	return temp;
}

string Parser::getColonDash(int input, queue<Token>& Char)
{
	checkIfNone(Char);
	string temp;

	if(Char.front().getChar()=="COLON_DASH")
	{
		temp=" ";
		temp+=Char.front().getInfo();
		temp+=" ";
		Char.pop();
	}

	else
	{
		string des ="error";
		throw des;
	}

	return temp;
}

string Parser::getQMark(int input, queue<Token>& Char)
{
	string temp;
	checkIfNone(Char);

	if(Char.front().getChar()=="Q_MARK")
	{
		temp=Char.front().getInfo();
		Char.pop();
	}

	else
	{
		string des ="error";
		throw des;
	}

	return temp;
}

void Parser::checkFacts()
{
	queue<string> temp;
	stringstream ss;
	string kurt;
	string counter;
	int count=0;
	int input;
	Parameter freshParam;
	temp.push(getFacts());
	while(facts.size()!=0)
	{
		input=facts.front().fetchLineNum();
		kurt="  ";
		kurt+=getID(input, facts);
		kurt+=getLParen(input, facts);
		kurt+=freshParam.fectchParam(input,facts,universeList);
		kurt+=getRParen(input, facts);
		kurt+=getPeriod(input, facts);
		count++;
		temp.push(kurt);
	}
	ss << "Facts" << "(" << count << ")" << ":";
	ss >> counter;

	temp.pop();
	finishedList.push(counter);
	while(temp.size()!=0)
	{
		finishedList.push(temp.front());
		temp.pop();
	}
}

string Parser::getFacts()
{
	string temp;
	int input;
	if(facts.front().getChar()=="FACTS")
	{
		temp=facts.front().getInfo();
		input=facts.front().fetchLineNum();
		facts.pop();
	}
	else
	{
		string des="error";
		throw des;
	}

	return temp+=getColon(facts);
}

string Parser::getRules()
{
	string temp;
	int input;
	if(rules.front().getChar()=="RULES")
	{
		temp=rules.front().getInfo();
		input=rules.front().fetchLineNum();
		rules.pop();
	}
	else
	{
		string des="error";
		throw des;
	}

	return temp+=getColon(rules);
}

void Parser::checkRules()
{
	queue<string> temp;
	stringstream ss;
	string kurt;
	string counter;
	int count=0;
	int input;
	Parameter freshParam;
	temp.push(getRules());
	while(rules.size()!=0)
	{
		input=rules.front().fetchLineNum();
		kurt="  ";
		kurt+=getID(input, rules);
		kurt+=getLParen(input, rules);
		kurt+=freshParam.fectchParam(input,rules,universeList);
		kurt+=getRParen(input, rules);
		kurt+=getColonDash(input, rules);
		kurt+=getID(input, rules);
		kurt+=getLParen(input, rules);
		kurt+=freshParam.fectchParam(input,rules,universeList);
		kurt+=getRParen(input,rules);

		while(rules.front().getChar()=="COMMA")
		{
			kurt+=getComma(input, rules);
			kurt+=getID(input, rules);
			kurt+=getLParen(input, rules);
			kurt+=freshParam.fectchParam(input,rules,universeList);
			kurt+=getRParen(input,rules);
		}

		kurt+=getPeriod(input,rules);
		count++;
		temp.push(kurt);
	}
	ss << "Rules" << "(" << count << ")" << ":";
	ss >> counter;

	temp.pop();
	finishedList.push(counter);
	while(temp.size()!=0)
	{
		finishedList.push(temp.front());
		temp.pop();
	}
}

string Parser::getQueries()
{
	string temp;
	int input=queries.front().fetchLineNum();
	if(queries.front().getChar()=="QUERIES")
	{
		temp=queries.front().getInfo();
		input=queries.front().fetchLineNum();
		queries.pop();
	}
	else
	{
		string des="error";
		throw des;
	}

	return temp+=getColon(queries);	
}

void Parser::checkQueries()
{
	queue<string> temp;
	stringstream ss;
	string kurt;
	string counter;
	Parameter freshParam;
	int count=0;
	int input;
	temp.push(getQueries());
	checkIfNone(queries);
	while(queries.size()!=0)
	{
		input=queries.front().fetchLineNum();
		kurt="  ";
		kurt+=getID(input, queries);
		kurt+=getLParen(input, queries);
		kurt+=freshParam.fectchParam(input,queries,universeList);
		kurt+=getRParen(input, queries);
		kurt+=getQMark(input,queries);
		count++;
		temp.push(kurt);
	}
	ss << "Queries" << "(" << count << ")" << ":";
	ss >> counter;

	temp.pop();
	finishedList.push(counter);
	while(temp.size()!=0)
	{
		finishedList.push(temp.front());
		temp.pop();
	}
}

Token Parser::getError()
{
	if(schemes.size()!=0)
	{
		return schemes.front();
	}
	else if(facts.size()!=0)
	{
		return facts.front();
	}
	else if(rules.size()!=0)
	{
		return rules.front();
	}
	else
	{
		return queries.front();
	}
}

void Parser::checkIfNone(queue<Token>& Char)
{
	if(Char.size()==0)
	{
		string des = "error";
		throw des;
	}
	return;
}

void Parser::outToFile(ofstream& outFile)
{
	set<string>::iterator it;
	outFile << "Success!" << endl;
	while(finishedList.size()!=0)
	{
		outFile << finishedList.front() << endl;
		finishedList.pop();
	}
	outFile << "Domain("<<universeList.size()<<"):" << endl;
	for(it=universeList.begin(); it!=universeList.end(); it++)
	{
		 outFile <<"  "<<(*it) << endl;
	}
}
