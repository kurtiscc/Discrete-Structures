#pragma once

#include <iostream>
#include <ctype.h>
#include <vector>


using namespace std;

class Lexical_Analyzer
{

	private:

	int counter;
	int total_tokens;
	bool sneech;
	vector<string> token_name;
	vector<string> token_icon;
	vector<int> token_count;

	public:

	Lexical_Analyzer()
	{
		counter=1;
		total_tokens=0;
		sneech = false;
	}

	void find_token(ifstream& inFile, ofstream& outFile)
	{
		char input;
	

		while (inFile.get(input))
		{

			if(isalpha(input))
			{
				is_string(input, inFile, outFile);
			}
			else
			{
				is_punct(inFile, input, outFile);
			}
			if(sneech)
				break;
		}
		if(!sneech)

		for(int i = 0; i<token_name.size(); i++)
		{
			outFile << "(" << token_name[i] << "," << token_icon[i] << "," << token_count[i] << ")" << endl;
		}
		outFile<<"Total Tokens = "<<total_tokens<<endl;

	
	}
	void is_punct(ifstream& inFile, char t, ofstream& outFile)
	{
		switch (t)
		{
			case(','):
			{
				token_name.push_back("COMMA");
				token_icon.push_back("\",\"");
				token_count.push_back(counter);
				//outFile<<"(COMMA,\",\","<<counter<<")"<<endl;
				total_tokens++;
				break;
			}

			case('.'):
			{
				token_name.push_back("PERIOD");
				token_icon.push_back("\".\"");
				token_count.push_back(counter);
				//outFile<<"(PERIOD,\".\","<<counter<<")"<<endl;
				total_tokens++;
				break;
			}

			case('?'):
			{
				token_name.push_back("Q_MARK");
				token_icon.push_back("\"?\"");
				token_count.push_back(counter);
				//outFile<<"(Q_MARK,\"?\","<<counter<<")"<<endl;
				total_tokens++;
				break;
			}

			case('('):
			{
				token_name.push_back("LEFT_PAREN");
				token_icon.push_back("\"(\"");
				token_count.push_back(counter);
				//outFile<<"(LEFT_PAREN,\"(\","<<counter<<")"<<endl;
				total_tokens++;
				break;
			}

			case(')'):
			{
				token_name.push_back("RIGHT_PAREN");
				token_icon.push_back("\")\"");
				token_count.push_back(counter);
				//outFile<<"(RIGHT_PAREN,\")\","<<counter<<")"<<endl;
				total_tokens++;
				break;
			}

			case(':'):
			{
				if(inFile.get()!='-')
				{
					token_name.push_back("COLON");
					token_icon.push_back("\":\"");
					token_count.push_back(counter);
					//outFile<<"(COLON,\":\","<<counter<<")"<<endl;
					inFile.unget();
					total_tokens++;
				}
				else
				{
					token_name.push_back("COLON_DASH");
					token_icon.push_back("\":-\"");
					token_count.push_back(counter);
					//outFile<<"(COLON_DASH,\":-\","<<counter<<")"<<endl;
					total_tokens++;
				}
				break;
			}

			case('#'):
			{
				while(inFile.get()!='\n')
				{}
				counter++;
				break;
			}

			case('\''):
			{
				get_string(inFile, outFile);
				break;
			}
			
			case('\n'):
			{
				counter++;
				break;
			}

			default:

			if(!isspace(t))
			{
				outFile<<"Error on line "<<counter<<endl;
				sneech = true;
				break;
			}

		}
	}
	void is_string(char t, ifstream& inFile, ofstream& outFile)
	{
		string id;
		id=id+t;
		char input;
		while (inFile.get(input))
		{
			if(!isalnum(input))
			{
				get_id(id, outFile);
				inFile.unget();
				break;
			}
			else
			{
				id=id+input;
			}

		}
	}
	void get_string(ifstream& inFile, ofstream& outFile)
	{
		string id;
	
		char input;
		while (inFile.get(input))
		{
			if(input=='\'')
			{
				token_name.push_back("STRING");
				token_icon.push_back("\""+id+"\"");
				token_count.push_back(counter);
				//outFile<<"(STRING,\""<<id<<"\","<<counter<<")"<<endl;
				total_tokens++;
				break;
			}
			else if(input=='\n')
			{       
	
				outFile<<"Error on line "<<counter<<endl;
				sneech = true;
				break;
			}
			else
			{
				id=id+input;
			}

		}
		if(input!='\''&&input!='\n')
		{
			outFile<<"Error on line "<<counter<<endl;
			sneech = true;
		}
		

	}
	void get_id(string ID, ofstream& outFile)
	{
		if(ID=="Queries")
		{
				token_name.push_back("QUERIES");
				token_icon.push_back("\""+ID+"\"");
				token_count.push_back(counter);
				//outFile<<"(QUERIES,\""<<ID<<"\","<<counter<<")"<<endl;
				total_tokens++;
		}
		else if(ID=="Schemes")
		{
				token_name.push_back("SCHEMES");
				token_icon.push_back("\""+ID+"\"");
				token_count.push_back(counter);
				//outFile<<"(SCHEMES,\""<<ID<<"\","<<counter<<")"<<endl;
				total_tokens++;
		}
		else if(ID=="Facts")
		{
				token_name.push_back("FACTS");
				token_icon.push_back("\""+ID+"\"");
				token_count.push_back(counter);
				//outFile<<"(FACTS,\""<<ID<<"\","<<counter<<")"<<endl;
				total_tokens++;
		}
		else if(ID=="Rules")
		{
				token_name.push_back("RULES");
				token_icon.push_back("\""+ID+"\"");
				token_count.push_back(counter);
				//outFile<<"(RULES,\""<<ID<<"\","<<counter<<")"<<endl;
				total_tokens++;
		}
		else
		{
			token_name.push_back("ID");
			token_icon.push_back("\""+ID+"\"");
			token_count.push_back(counter);
			//outFile<<"(ID,\""<<ID<<"\","<<counter<<")"<<endl;
			total_tokens++;
		}
	}
};





