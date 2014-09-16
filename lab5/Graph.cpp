#include "Graph.h"

Graph::Graph()
{
	num_currr=1;
}

void Graph::add_new_node(string my_new_node)
{
	pair<string,Node> temp;
	temp.first=my_new_node;
	graph_structure.insert(temp);
}

void Graph::add_new_edge(string node, string nouveau_edge)
{
	graph_structure[node].List.insert(nouveau_edge);
}

string Graph::graph_dependancy(Datalog& t)
{
	construct_graph(t);

	string temp="Dependency Graph\n";

	for (map<string, Node>::iterator it1=graph_structure.begin(); it1!=graph_structure.end(); ++it1)
	{
		temp+="  "+(*it1).first+":";
		for (set <string>::iterator it2=(it1->second.List.begin()); it2!=(it1->second.List.end()); ++it2)
			temp+=" "+(*it2);
		temp+="\n";
	}
	temp+="\n";
	return temp;
}

void Graph::construct_graph(Datalog& t)
{
	add_nodes(t.queries_list, t.rules_list);

	add_edges(t.queries_list, t.rules_list);
}

void Graph::add_nodes(vector <predicate>& t1, vector <Rule>& t2)
{
	for (int i=0; i<t1.size(); i++)
	{
		ostringstream my_strm;

		my_strm<<"Q"<<i+1;

		string ID=my_strm.str();
		
		add_new_node(ID);
	}
	for (int i=0; i<t2.size(); i++)
	{
		ostringstream my_strm;

		my_strm<<"R"<<i+1;

		string ID=my_strm.str();

		add_new_node(ID);
	}
}

void Graph::add_edges(vector <predicate>& t1, vector <Rule>& t2)
{
	for (int i=0; i<t1.size(); i++)
	{
		for (int j=0;j<t2.size();j++)
		{
			ostringstream my_strm;
			my_strm<<"R"<<j+1;
			string ID2=my_strm.str();
			if (t1[i]==t2[j].pred_list[0])
			{
				ostringstream my_strm2;
				my_strm2<<"Q"<<i+1;
                string ID=my_strm2.str();
				add_new_edge(ID, ID2);
			} 
			for (int a=1;a<t2[j].pred_list.size();a++)
				for (int b=0;b<t2.size();b++)
					if (t2[j].pred_list[a]==t2[b].pred_list[0])
					{
						ostringstream my_strm2;
						my_strm2<<"R"<<b+1;
						string ID3=my_strm2.str();
						add_new_edge(ID2, ID3);
					}
		}
	}
}

string Graph::post_order_nums(int q_num)
{
	set <pair<string, string> > temp;
	ostringstream my_strm;
	my_strm<<"Q"<<q_num+1;
	string beginning_node=my_strm.str();
	d_f_s(beginning_node, temp);
	string result="  Postorder Numbers\n";
	for (set<pair<string, string> >::iterator it=temp.begin(); it!=temp.end(); ++it){
		result+="    "+it->first+": "+it->second+"\n";
	}
    result+="\n";
	return result;
}

void Graph::d_f_s(string beginning_node, set <pair<string, string> >& temp)
{
	graph_structure[beginning_node].visitee=true;
	for (set<string>::iterator it1=graph_structure[beginning_node].List.begin(); it1!=graph_structure[beginning_node].List.end(); ++it1)
	{
		for (map<string, Node>::iterator it2=graph_structure.begin(); it2!=graph_structure.end(); ++it2)
			if (*it1==it2->first)
			{
				if (it2->second.visitee==false)
					d_f_s(it2->first, temp);
				break;
			}
	}
	graph_structure[beginning_node].Postorder=num_currr;
	ostringstream my_strm;
	my_strm << num_currr;
	temp.insert(pair<string, string>(beginning_node,my_strm.str()));
	num_currr++;
	return;
}

string Graph::rule_eval_order(int q_num, vector <int>& o_for_eval)
{
	for (map<string, Node>::iterator it=graph_structure.begin(); it!=graph_structure.end(); ++it)
		it->second.visitee=false;
	string temp;
	ostringstream my_strm;
	my_strm<<"Q"<<q_num+1;
	string beginning_node=my_strm.str();
	rule_eval_order_r(beginning_node, o_for_eval, temp);
    temp="  Rule Evaluation Order\n"+temp+"\n";
	return temp;
}

void Graph::rule_eval_order_r(string beginning_node, vector <int>& o_for_eval, string& temp)
{
	graph_structure[beginning_node].visitee=true;
	for (set<string>::iterator it1=graph_structure[beginning_node].List.begin(); it1!=graph_structure[beginning_node].List.end(); ++it1)
	{
		for (map<string, Node>::iterator it2=graph_structure.begin(); it2!=graph_structure.end(); ++it2)
			if (*it1==it2->first)
			{
				if (it2->second.visitee==false)
					rule_eval_order_r(it2->first, o_for_eval, temp);
				break;
			}

	}
	if (beginning_node.substr(0,1)!="Q")
	{
		temp+="    "+beginning_node+"\n";
		string numberInID=beginning_node.substr(1,beginning_node.size()-1);
		istringstream my_strm(numberInID);
		int n;
		my_strm>>n;
		o_for_eval.push_back(n-1);
	}
	return;
}

bool Graph::backward_edges(int q_num, string& temp)
{
	for (map<string, Node>::iterator it=graph_structure.begin(); it!=graph_structure.end(); ++it)
		it->second.visitee=false;
	ostringstream my_strm;
	my_strm<<"Q"<<q_num+1;
	string beginning_node=my_strm.str();
	map <string,set <string> > BackwardEgdes;
	bool result=false;
	backward_edges_r(beginning_node, BackwardEgdes, result);
	for (map<string, set <string> >::iterator it1=BackwardEgdes.begin(); it1!=BackwardEgdes.end(); ++it1)
	{
		temp+="    "+it1->first+":";
		for (set <string>::iterator it2=it1->second.begin(); it2!=it1->second.end(); ++it2)
			temp+=" "+(*it2);
		temp+="\n";
	}
	temp="  Backward Edges\n"+temp+"\n";
	return result;
}

void Graph::backward_edges_r(string beginning_node, map<string,set <string> >& temp, bool& is_backwards)
{
	graph_structure[beginning_node].visitee=true;
	for (set<string>::iterator it1=graph_structure[beginning_node].List.begin(); it1!=graph_structure[beginning_node].List.end(); ++it1)
	{
		for (map<string, Node>::iterator it2=graph_structure.begin(); it2!=graph_structure.end(); ++it2)
			if (*it1==it2->first)
			{
				if (it2->second.Postorder>=graph_structure[beginning_node].Postorder)// && it2->second.Postorder!=0)
					{
						is_backwards=true;
						insert_in_temp(beginning_node, it2->first, temp);
					}	
				if (it2->second.visitee==false)
					backward_edges_r(it2->first, temp, is_backwards);
				break;
			}
	}

	return;
}


void Graph::insert_in_temp(string node_1, string node_2, map<string,set <string> >& temp)
{
	if (node_1.substr(0,1)!="Q" && node_2.substr(0,1)!="Q")
	{
	if (temp.find(node_1)==temp.end())
	{
		pair<string,set <string> > temporary_pair;
		temporary_pair.first=node_1;
	    temp.insert(temporary_pair);
	}
	temp[node_1].insert(node_2);
	}
}

void Graph::clear()
{
	num_currr=1;
	for (map<string, Node>::iterator it=graph_structure.begin(); it!=graph_structure.end(); ++it)
	{
		it->second.visitee=false;
		it->second.Postorder=0;
	}
}

