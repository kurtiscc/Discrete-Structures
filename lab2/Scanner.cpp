#include "Scanner.h"

bool Scanner::identifier(string input)
{
	bool findError;
	stringstream ss;
	string sneech;
	string current;
	string temp;
	string output;
	queue<string>listOfWords;
	queue<string>listOfChars;
	ss << input;


	listOfWords=toWords(ss);

	while(listOfWords.size() > 0)
	{
		listOfChars = toChar(listOfWords, output);
		findError = parse(listOfChars, output);
		if(findError==true)
		{
			return true;
		}
		
		if(comment == true)
		{
			comment = false;
			break;
		}

	}
	if(inInput == true)
	{
		string inputString;
		stringstream temp;
		temp << lineCounter;
		temp >> inputString;
		error.push("Error on input ");
		error.push(inputString);
		return true;
	}
	else
	{
		lineCounter++;
		return false;
	}
}

bool Scanner::parse(queue<string> &listOfChars, string &output)
{
	string result;
	while(listOfChars.size()>0)
	{
		string input=listOfChars.front();
		listOfChars.pop();
		result=verifyChar(input);
		if(result=="break")
		{
			comment=true;
			break;
		}
		if(result=="STRING"&&inInput==false)
		{
			string inputString;
			stringstream temp;
			finishedList.push("STRING");
			finishedList.push(output);
			temp<<lineCounter;
			temp>>inputString;
			finishedList.push(inputString);
		}
		if(inInput==true)
		{
			output=option1(input, output, result);
		}
		else if(result!="char")
		{
			output=option2(input, output, result, listOfChars);
		}
		else
		{
			output=option3(input, output, result, listOfChars);
		}
			
		if(errorFind==true)
		{
			string inputString;
			stringstream temp;
			temp<<lineCounter;
			temp>>inputString;
			error.push("Error on input ");
			error.push(inputString);
			return true;
		}

	}
	return false;
}

queue<string> Scanner::toWords(stringstream &ss)
{

	string sneech;
	queue<string> listOfWords;
	while(ss>>sneech)
	{
		listOfWords.push(sneech);
	}
	return listOfWords;
}

queue<string> Scanner::toChar(queue<string> &listOfWords, string &output)
{
	string current;
	queue<string> listOfChars;
	current=listOfWords.front();
	listOfWords.pop();
	if(inInput==true)
	{
		output+=" ";
	}

	int i=0;
	while(i<current.size())
	{
		string character="a";
		character[0]=current[i];
		listOfChars.push(character);
		i++;
	}
	return listOfChars;
}

string Scanner::verifyChar(string character)
{
	if(ispunct(character[0]))
	{
		return checkPunc(character);
	}

	else
	{
		return "char";
	}
}

void Scanner::stringer()
{
	if (inInput==true)
	{
		inInput=false;
	}
	else
	{
		inInput=true;
	}
}

string Scanner::checkPunc(string character)
{
	if(character=="'")
		{
			stringer();
			return "STRING";
		}

		else if (character=="#")
		{
			return "break";
		}

		else if (character==":")
		{
			return "COLON";
		}

		else if (character=="-")
		{
			return "DASH";
		}

		else
		{
			map<string, string>::const_iterator it;
			it=tokenInput.find(character);
			if (it!=tokenInput.end())
			{
				string temp=(*it).second;
				return temp;
			}
			else
			{
				return "undef";
			}
		}
}

bool Scanner::validate(string output)
{
	string inputString;
	stringstream temp;
	map<string, string>::const_iterator it;
	it=tokenInput.find(output);
	if(isdigit(output[0]))
	{
		return true;
	}

	else if(it!=tokenInput.end())
	{
		finishedList.push((*it).second);
		finishedList.push(output);
		temp<<lineCounter;
		temp>>inputString;
		finishedList.push(inputString);
		return false;
	}
	else
	{
		finishedList.push("ID");
		finishedList.push(output);
		temp<<lineCounter;
		temp>>inputString;
		finishedList.push(inputString);
		return false;
	}
}

string Scanner::option1(string input, string output, string result)
{
	if(input!="'")
	{
		output+=input;
	}
	return output;
	
}

string Scanner::option2(string input, string output, string result, queue<string>&listOfChars)
{
	string inputString;
	stringstream temp;
	if(result=="STRING")
	{
		return "";
	}
	else if(result=="COLON"&&listOfChars.size()!=0)
	{
		if(listOfChars.front()=="-")
		{
			output+=input;
			listOfChars.pop();
			finishedList.push("COLON_DASH");
			finishedList.push(":-");
			temp<<lineCounter;
			temp>>inputString;
			finishedList.push(inputString);
			return "";
		}
		else
		{
			output+=input;
			finishedList.push("COLON");
			finishedList.push(":");
			temp<<lineCounter;
			temp>>inputString;
			finishedList.push(inputString);
			return "";
		}
	}
	else if(result=="undef"||result=="DASH")
	{
		errorFind=true;
		return "";
	}
	else
	{
		map<string, string>::const_iterator it;
		it=tokenInput.find(input);
		output+=input;
		finishedList.push((*it).second);
		finishedList.push(output);
		temp<<lineCounter;
		temp>>inputString;
		finishedList.push(inputString);
		return "";
	}
}

string Scanner::option3(string input, string output, string result, queue<string>&listOfChars)
{
	if(listOfChars.size()==0)
	{
		output+=input;
		errorFind=validate(output);
		return"";
	}
	else if(ispunct(listOfChars.front()[0]))
	{
		output+=input;
		errorFind=validate(output);
		return"";
	}
	else
	{
		return output+input;
	}
}

void Scanner::initiateError(ofstream &outFile)
{
	outFile<<error.front();
	error.pop();
	outFile<<error.front();
	error.pop();
	return;
}

int Scanner::write(ofstream &outFile)
{
	int count=0;
	while(finishedList.size()!=0)
	{
		outFile<<"("<<finishedList.front();
		finishedList.pop();
		outFile<<",\""<<finishedList.front();
		finishedList.pop();
		outFile<<"\","<<finishedList.front()<<")";
		finishedList.pop();
		outFile<<endl;
		count++;
	}
	return count;
}

vector<Token> Scanner::tokenify()
{
	vector<Token> TokenList;
	string temp1;
	string temp2;
	string temp3;
	int temp;

	while (finishedList.size()!=0)
	{
		temp1=finishedList.front();
		finishedList.pop();
		temp2=finishedList.front();
		finishedList.pop();
		temp3=finishedList.front();
		finishedList.pop();
		stringstream ss;
		ss<<temp3;
		ss>>temp;
		Token newtoken(temp, temp1, temp2);
		TokenList.push_back(newtoken);
	}

	return TokenList;
}