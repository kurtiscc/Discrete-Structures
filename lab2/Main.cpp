#include "Scanner.h"
#include "Parser.h"

Token outputError(Parser& parser);

int main(int argc, char *argv[])
{
	ifstream inFile;
	ofstream outFile;

	bool error;
	string input;
	
	vector<Token>TokenList;

	Scanner analyze;

	inFile.open(argv[1]);
	outFile.open(argv[2]);

	while(getline(inFile,input))
	{
		error=analyze.identifier(input);

		if(error==true)
		{
			analyze.initiateError(outFile);
			return 0;
		}
	}
	TokenList=analyze.tokenify();

	Parser parse(TokenList);

	try
	{
		parse.parse();
	}

	catch(string a)
	{
		Token temp=outputError(parse);
		outFile<<"Failure!"<<endl;
		outFile<<"  "<<"("<<temp.getChar()<<","<<"\""<<temp.getInfo()<<"\""<<","<<temp.fetchLineNum()<<")"<<endl;
		return 0;
	}
	
	parse.outToFile(outFile);
	return 0;
}

Token outputError(Parser& parser)
{
	return parser.getError();
}