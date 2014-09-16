#pragma once

#include <iostream>
#include <string>

using namespace std;

class Token
{
private:
	int numLine;
	string Char;
	string text;

public:
	Token(int lineInput, string inputType, string textInput)
	{
		numLine=lineInput;
		Char=inputType;
		text=textInput;
	}

	virtual ~Token(){}

	int fetchLineNum()
	{
		return numLine;
	}
	string getChar()
	{
		return Char;
	}
	string getInfo()
	{
		return text;
	}
};


