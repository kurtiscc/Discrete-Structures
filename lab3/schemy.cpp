#include "schemy.h"

string Scheme::at(int kurt1)
{
return attributes[kurt1];
}
void Scheme::add(string name)
{
	bool has=false;
	for (int i=0; i<attributes.size(); i++)
		if (attributes[i]==name)
		{
			has=true;
			break;
		}
	if (!has)
		attributes.push_back(name);
}
int Scheme::size()
{
	return attributes.size();
}
void Scheme::rename(int kurt1, string& name)
{
	attributes[kurt1]=name;
}