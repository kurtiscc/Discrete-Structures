#pragma once

#include <string>
#include <set>

using namespace std;

struct Node
{
	set <string> List;

	int Postorder;

	bool visitee;

	Node(){visitee=false; Postorder=0;}
};