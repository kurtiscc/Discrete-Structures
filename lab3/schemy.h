#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Scheme
{
public:
	Scheme(){}
	~Scheme(){}

	string at(int kurt1);
	void add(string name);
	int size();
	void rename(int kurt1, string& name);

private:

	vector<string> attributes;


};