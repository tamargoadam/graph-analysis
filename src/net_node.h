#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <regex>
#include <unordered_map>

using namespace std;

struct netNode {
    public: 
        int id;
        unordered_map<int, pair<int, string>> ratings; // map <movie_number, pair<rating, date>> to keep track of all of a user's ratings

        netNode(int id, int movie, int rating, string date);

        //time_t convertDate(string dateString);
        void addRating(int movie, int rating, string date);

};