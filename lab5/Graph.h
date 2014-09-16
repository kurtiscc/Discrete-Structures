#pragma once

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <set>

#include "Node.h"
#include "Predicate.h"
#include "Datalog.h"
#include "Rule.h"

using namespace std;

class Graph
{

public:

	Graph();

	~Graph(){}

	void add_new_node(string my_new_node);  

	void add_new_edge(string node, string nouveau_edge);

	string graph_dependancy(Datalog& t);

    void construct_graph(Datalog& t);

	void add_nodes(vector <predicate>& t1, vector <Rule>& t2);

	void add_edges(vector <predicate>& t1, vector <Rule>& t2);

	string post_order_nums(int q_num);

	void d_f_s(string beginning_node, set <pair<string, string > >& temp);

	string rule_eval_order(int q_num, vector <int>& o_for_eval);

	void rule_eval_order_r(string beginning_node, vector <int>& o_for_eval, string& temp);

	bool backward_edges(int q_num, string& temp);

    void backward_edges_r(string beginning_node, map<string, set <string> >& temp, bool& is_backwards);

	void insert_in_temp(string node_1, string node_2, map<string, set <string> >& temp);

    void clear();	


private:

	map <string, Node> graph_structure;
	
	int num_currr;

};
