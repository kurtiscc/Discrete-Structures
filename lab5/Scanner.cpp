#include "Parameter.h"
#include "Scanner.h"


using namespace std;

Scanner::Scanner()
{
	line_counter=1;
	tok_counter=0;
	desirae = false;
}

vector <string> Scanner::readFile(ifstream& inFile, ofstream& outFile)
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

		if(desirae)
			break;
	}

	return tokenator;
}

void Scanner::readChar(ifstream& inFile, char t, ofstream& outFile)
{
	switch (t)
	{
		case(','):
		{
			ostringstream stream;
			stream<<"(COMMA,\",\","<<line_counter<<")"<<endl;
			tokenator.push_back(stream.str());

			tok_counter++;
			break;
		}

		case('.'):
		{
			ostringstream stream;
			stream<<"(PERIOD,\".\","<<line_counter<<")"<<endl;
			tokenator.push_back(stream.str());

			tok_counter++;
			break;
		}

		case('?'):
		{
			ostringstream stream;
			stream<<"(Q_MARK,\"?\","<<line_counter<<")"<<endl;
			tokenator.push_back(stream.str());

			tok_counter++;
			break;
		}

		case('('):
		{
			ostringstream stream;
			stream<<"(LEFT_PAREN,\"(\","<<line_counter<<")"<<endl;
			tokenator.push_back(stream.str());

			tok_counter++;
			break;
		}

		case(')'):
		{
			ostringstream stream;
			stream<<"(RIGHT_PAREN,\")\","<<line_counter<<")"<<endl;
			tokenator.push_back(stream.str());

			tok_counter++;
			break;
		}

		case(':'):
		{
			if(inFile.get()!='-')
			{
				ostringstream stream;
				stream<<"(COLON,\":\","<<line_counter<<")"<<endl;
				tokenator.push_back(stream.str());
				inFile.unget();
				tok_counter++;
			}
			else
			{
				ostringstream stream;
				stream<<"(COLON_DASH,\":-\","<<line_counter<<")"<<endl;
				tokenator.push_back(stream.str());
				tok_counter++;
			}
			break;
		}

		case('#'):
		{
			while(inFile.get()!='\n')
			{}
			line_counter++;
			break;
		}

		case('\''):
		{
			processString(inFile, outFile);
			break;
		}
		
		case('\n'):
		{
			line_counter++;
			break;
		}

		default:

		if(!isspace(t))
		{
			ostringstream stream;
			stream<<"Input Error on line "<<line_counter<<endl;
			tokenator.push_back(stream.str());
			desirae = true;
			break;
		}

	}
}
void Scanner::readID(char t, ifstream& inFile, ofstream& outFile)
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
void Scanner::processString(ifstream& inFile, ofstream& outFile)
{
	string id;
	
	char temp;
	while (inFile.get(temp))
	{
		if(temp=='\'')
		{
			ostringstream stream;
			stream << "(STRING,\""<<id<<"\","<<line_counter<<")" << endl;
			tokenator.push_back(stream.str());

			tok_counter++;
			break;
		}
		else if(temp=='\n')
		{
			ostringstream stream;
			stream << "Input Error on line "<<line_counter << endl;
			tokenator.push_back(stream.str());

			desirae = true;
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
		stream<<"Input Error on line "<<line_counter << endl;
		tokenator.push_back(stream.str());
		desirae = true;
	}
		

}
void Scanner::processID(string ID, ofstream& outFile)
{
	if(ID=="Queries")
	{
			ostringstream stream;
			stream<<"(QUERIES,\""<<ID<<"\"," << line_counter << ")"<<endl;
			tokenator.push_back(stream.str());

			tok_counter++;
	}
	else if(ID=="Schemes")
	{
			ostringstream stream;
			stream<<"(SchemeES,\""<<ID<<"\"," << line_counter << ")" << endl;
			tokenator.push_back(stream.str());

			tok_counter++;
	}
	else if(ID=="Facts")
	{
			ostringstream stream;
			stream<<"(FACTS,\""<<ID<<"\"," << line_counter << ")" << endl;
			tokenator.push_back(stream.str());

			tok_counter++;
	}
	else if(ID=="Rules")
	{
			ostringstream stream;
			stream << "(RULES,\"" << ID << "\"," << line_counter<<")" << endl;
			tokenator.push_back(stream.str());

			tok_counter++;
	}
	else
	{
		ostringstream stream;
		stream << "(ID,\"" << ID << "\"," << line_counter << ")" << endl;
		tokenator.push_back(stream.str());

		tok_counter++;
	}
}





