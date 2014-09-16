#include "scanner.h"
#include "Parameter.h"

using namespace std;

scanner::scanner()
{
	lineCount=1;
	tokenCount=0;
	anya = false;
}

vector <string> scanner::readFile(ifstream& inFile, ofstream& outFile)
{
	char temp;
	

	while (inFile.get(temp))
	{

		if(isalpha(temp))
		{
			readID(temp, inFile, outFile);
		}
		else
		{
			readChar(inFile, temp, outFile);
		}
		if(anya)
			break;
	}

	return tokens;
}
void scanner::readChar(ifstream& inFile, char t, ofstream& outFile)
{
	switch (t)
	{
		case(','):
		{
			ostringstream stream;
			stream<<"(COMMA,\",\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
			break;
		}

		case('.'):
		{
			ostringstream stream;
			stream<<"(PERIOD,\".\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
			break;
		}

		case('?'):
		{
			ostringstream stream;
			stream<<"(Q_MARK,\"?\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
			break;
		}

		case('('):
		{
			ostringstream stream;
			stream<<"(LEFT_PAREN,\"(\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
			break;
		}

		case(')'):
		{
			ostringstream stream;
			stream<<"(RIGHT_PAREN,\")\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
			break;
		}

		case(':'):
		{
			if(inFile.get()!='-')
			{
				ostringstream stream;
				stream<<"(COLON,\":\","<<lineCount<<")"<<endl;
				tokens.push_back(stream.str());
				inFile.unget();
				tokenCount++;
			}
			else
			{
				ostringstream stream;
				stream<<"(COLON_DASH,\":-\","<<lineCount<<")"<<endl;
				tokens.push_back(stream.str());
				tokenCount++;
			}
			break;
		}

		case('#'):
		{
			while(inFile.get()!='\n')
			{}
			lineCount++;
			break;
		}

		case('\''):
		{
			processString(inFile, outFile);
			break;
		}
		
		case('\n'):
		{
			lineCount++;
			break;
		}

		default:

		if(!isspace(t))
		{
			ostringstream stream;
			stream<<"Input Error on line "<<lineCount<<endl;
			tokens.push_back(stream.str());
			anya = true;
			break;
		}

	}
}
void scanner::readID(char t, ifstream& inFile, ofstream& outFile)
{
	string id;
	id=id+t;
	char temp;
	while (inFile.get(temp))
	{
		if(!isalnum(temp))
		{
			processID(id, outFile);
			inFile.unget();
			break;
		}
		else
		{
			id=id+temp;
		}

	}
}
void scanner::processString(ifstream& inFile, ofstream& outFile)
{
	string id;
	
	char temp;
	while (inFile.get(temp))
	{
		if(temp=='\'')
		{
			ostringstream stream;
			stream<<"(STRING,\""<<id<<"\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
			break;
		}
		else if(temp=='\n')
		{
			ostringstream stream;
			stream<<"Input Error on line "<<lineCount<<endl;
			tokens.push_back(stream.str());

			anya = true;
			break;
		}
		else
		{
			id=id+temp;
		}

	}
	if(temp!='\''&&temp!='\n')
	{
		ostringstream stream;
		stream<<"Input Error on line "<<lineCount<<endl;
		tokens.push_back(stream.str());
		anya = true;
	}
		

}
void scanner::processID(string ID, ofstream& outFile)
{
	if(ID=="Queries")
	{
			ostringstream stream;
			stream<<"(QUERIES,\""<<ID<<"\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
	}
	else if(ID=="Schemes")
	{
			ostringstream stream;
			stream<<"(SCHEMES,\""<<ID<<"\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
	}
	else if(ID=="Facts")
	{
			ostringstream stream;
			stream<<"(FACTS,\""<<ID<<"\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
	}
	else if(ID=="Rules")
	{
			ostringstream stream;
			stream<<"(RULES,\""<<ID<<"\","<<lineCount<<")"<<endl;
			tokens.push_back(stream.str());

			tokenCount++;
	}
	else
	{
		ostringstream stream;
		stream<<"(ID,\""<<ID<<"\","<<lineCount<<")"<<endl;
		tokens.push_back(stream.str());

		tokenCount++;
	}
}





