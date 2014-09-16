#include <iostream>
#include <string>
using namespace std;
class Parameter
{
private:

public:
	Parameter(){};
	virtual ~Parameter(){};
	string define(queue<Token>& Char, int input)
	{
		if(Char.front().getChar()=="STRING")
		{
			string temp;
			temp="'";
			temp+=Char.front().getInfo();
			temp+="'";
			Char.pop();
			return temp;
		}
		else if(Char.front().getChar()=="ID"||Char.front().getChar()=="COMMA")
		{
			string temp;
			temp=Char.front().getInfo();
			Char.pop();
			return temp;
		}
		else
		{
			string a="error";
			throw a;
		}
	}

	string define(queue<Token>& Char, int input, set<string>& universeList)
	{
		if(Char.front().getChar()=="STRING")
		{
			string temp;
			temp="'";
			temp+=Char.front().getInfo();
			temp+="'";
			universeList.insert(temp);
			Char.pop();
			return temp;
		}
		else if(Char.front().getChar()=="ID"||Char.front().getChar()=="COMMA")
		{
			string temp;
			temp=Char.front().getInfo();
			Char.pop();
			return temp;
		}
		else
		{
			string a="error";
			throw a;
		}
	}

	string fectchParam(int input, queue<Token>& Char)
	{
		string temp="";
		string detector;

		if(Char.front().getChar()=="RIGHT_PAREN")
		{
			string a="error";
			throw a;
		}

		while(Char.front().getChar()!="RIGHT_PAREN")
		{
			detector=Char.front().getChar();
			if(Char.size()==0)
			{
				string a="error";
				throw a;
			}
			temp+=define(Char,input);
		}
		if(detector=="COMMA")
		{
			string a="error";
			throw a;
		}
		return temp;
	}

	string fectchParam(int input, queue<Token>& Char, set<string>& universeList)
	{
		string temp="";
		string detector;
		
		if(Char.front().getChar()=="RIGHT_PAREN")
		{
			string a="error";
			throw a;
		}

		while(Char.front().getChar()!="RIGHT_PAREN")
		{
			detector=Char.front().getChar();
			if(Char.size()==0)
			{
				string a="error";
				throw a;
			}
			temp+=define(Char,input,universeList);
		}
		if(detector=="COMMA")
		{
			string a="error";
			throw a;
		}
		return temp;
	}
};
