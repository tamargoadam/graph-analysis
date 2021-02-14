#include "graph_make.h"

using namespace std;

netNode::netNode(string line)
{
    int id = stoi(line.substr(0, line.find(',')));
    line = line.substr(line.find(',') + 1, line.length() - 1);
    int rating = stoi(line.substr(0, line.find(',')));
    string dateString = line.substr(line.find(',') + 1, line.length() - 1);
}

time_t netNode::convertDate(string dateString) {
    struct tm tm;
    stringstream ds(dateString);

    ds >> get_time(&tm, "%Y-%m-%d");
    return mktime(&tm);
}

void netNode::addRating(int movie, int rating, string date)
{
    this->ratings[movie] = make_pair(rating, convertDate(date));
}


Graph<netNode*> * buildGraph(vector<string> filenames)
{
    unordered_map<int, netNode *> nodes;

    ifstream data;
    for (auto filename: filenames) {
        data.open(filename);
        string line = "";

        regex movie_header("[0-9]+:");

        int movie = 0;

        while (getline(data, line))
        {
            if (regex_match(line, movie_header))
                movie = stoi(line);

            else
            {
                int id = stoi(line.substr(0, line.find(',')));

                if (nodes.find(id) != nodes.end())
                {
                    line = line.substr(line.find(',') + 1, line.length() - 1);
                    int rating = stoi(line.substr(0, line.find(',')));
                    string dateString = line.substr(line.find(',') + 1, line.length() - 1);

                    nodes[id]->addRating(movie, rating, dateString);
                }

                else
                {
                    nodes[id] = new netNode(line);
                }
            }
        }
    }
    Graph<netNode*> *graph = new Graph<netNode*>();
    vector<netNode*> nodesVector;

    for (auto const& n : nodes) 
        nodesVector.push_back(n.second);

    graph->load_nodes(nodesVector);
    return graph;
}

void adjCrit_1(Graph<netNode*>* graph) {
    for (auto node : graph)
}