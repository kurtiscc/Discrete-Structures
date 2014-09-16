#include "interpreter.h"

void interpreter::start(string filename, DP& t)
{
	outFile.open(filename.c_str());
	Schemes(t.scheme_list);
	Facts(t.facts_list);
	Queries(t.queries_list);


}
void interpreter::Schemes(vector <predicate>& t)
{
	Relation temp;
	for(int i=0; i<t.size(); i++)
	{
		temp.setName(t[i].getID());
		for(int b=0; b<t[i].getSize(); b++)
		{
			temp.setValue(t[i].getParam(b));
		}
		DataBase.add(temp);
	}
}
void interpreter::Facts(vector <predicate>& t)
{
	for (int i=0; i<t.size(); i++)
	{
		for (int j=0; j<DataBase.DB_vec.size(); j++)
			if (DataBase.DB_vec[j].getName()==t[i].getID())
			{
				DataBase.DB_vec[j].setTuple(t[i].toTuple());
				break;
			}
	}
}
void interpreter::Queries(vector <predicate>& t)
{

	for (int i=0; i<t.size(); i++)
		for (int j=0; j<DataBase.DB_vec.size(); j++)
		{
			if (t[i].getID()==DataBase.DB_vec[j].getName())
			{
				Relation temp=DataBase.DB_vec[j];
				vector <int> indexParam;
				for (int x=0; x<t[i].getSize(); x++)
					Parameter(t[i].getVector(), x, temp, indexParam);
				temp=temp.project(indexParam);
				for (int z=0; z<indexParam.size(); z++)
					temp=temp.rename(t[i].getVector()[indexParam[z]].getParam(), z);
				printToFile (t[i], temp);
				break;
			}
		}
}
void interpreter::Parameter(vector <parameter> parameterList, int kurt1, Relation& relatey, vector <int>& t)
{
	Relation result;
	bool select=false;
	if (parameterList[kurt1].getParam().substr(0,1)=="'")
	{
		relatey=relatey.select2(kurt1, parameterList[kurt1].getParam());
		select=true;
	}
	else
		for (int i=0; i<t.size(); i++)
		{
			if (parameterList[i].getParam()==parameterList[kurt1].getParam())
			{
				relatey=relatey.select1(i, kurt1);
				select=true;
			}			
		}
		if (!select)
			t.push_back(kurt1);

}

void interpreter::printToFile(predicate& query, Relation relatey)
{
	outFile<<query.toString()<<"? ";
	if (relatey.getSize()==0)
		outFile<<"No"<<endl;
	else
	{
		if (relatey.empty(relatey))
			outFile<<"Yes(1)"<<endl;
		else
			outFile<<"Yes("<<relatey.getSize()<<")"<<endl<<relatey.toString();	
	}

}
