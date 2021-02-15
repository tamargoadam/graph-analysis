#include "net_node.h"

using namespace std;

netNode::netNode(int id, int movie, int rating, string date)
{
    this->id = id;
    this->ratings[movie] = make_pair(rating, date);
}


// time_t netNode::convertDate(string dateString) {
//     struct tm tm;
//     stringstream ds(dateString);

//     ds >> get_time(&tm, "%Y-%m-%d");
//     return mktime(&tm);
// }

void netNode::addRating(int movie, int rating, string date)
{
    this->ratings[movie] = make_pair(rating, (date));
}

