#include "graph_operations.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <regex>

using namespace std;


struct netNode {
    public: 
        int id;
        unordered_map<int, pair<int, time_t>> ratings; // map <movie_number, pair<rating, date>> to keep track of all of a user's ratings

        netNode(string line);

        time_t convertDate(string dateString);
        void addRating(int movie, int rating, string date);

        Graph<netNode*> *buildGraph(string filename);

};

