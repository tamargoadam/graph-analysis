#include "graph_make.h"

using namespace std;

Graph<netNode *> buildGraph(vector<string> filenames)
{
    unordered_map<int, netNode *> nodes;

    ifstream data;
    for (auto filename : filenames)
    {
        data.open(filename);
        string line = "";

        //regex movie_header("[0-9]+:");

        int movie = 0;

        while (getline(data, line))
        {
            if (line.find(':') < line.length())
            {
                movie = stoi(line);
                if (movie%1000 == 0) cout << "Movie:\t" << movie << endl;
            }
            else
            {
                int id = stoi(line);

                line = line.substr(line.find(',') + 1, line.length() - 1);
                int rating = stoi(line);
                string date = line.substr(line.find(',') + 1, line.length() - 1);
            

                if (nodes.find(id) != nodes.end())
                {
                    
                    nodes[id]->addRating(movie, rating, date);
                }

                else
                {
                    nodes[id] = new netNode(id, movie, rating, date);
                }
            }
        }
        data.close();
    }
    Graph<netNode *> graph;
    vector<netNode *> nodesVector;


    for (auto const &n : nodes)
        nodesVector.push_back(n.second);

    graph.load_nodes(nodesVector);
    
    cout << "Nodes Created: " << nodesVector.size() << endl;
    return graph;
}
