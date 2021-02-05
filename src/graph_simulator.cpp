#include "graph_simulator.h"

using namespace std;

Graph<int> cycle_graph(int n) {
    Graph<int> result;
    vector<int> v = vector<int>();
    
    for (int i=0; i<n; i++)
        v.push_back(i);
    result.load_nodes(v);
    
    result.add_edge(0, n-1);
    for (int i=1; i<n; i++)
        result.add_edge(i-1, i);

    return result;
};

Graph<int> complete_graph(int n) {
    Graph<int> result;
    vector<int> v = vector<int>();
    
    for (int i=0; i<n; i++)
        v.push_back(i);
    result.load_nodes(v);
    
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            result.add_edge(i, j);

    return result;
}

Graph<int> empty_graph(int n) {
    Graph<int> result;
    vector<int> v = vector<int>();
    
    for (int i=0; i<n; i++)
        v.push_back(i);
    result.load_nodes(v);

    return result;
}

Graph<int> heap(int n) {
    Graph<int> result;
    vector<int> v = vector<int>();
    
    for (int i=0; i<n; i++)
        v.push_back(i);
    result.load_nodes(v);
    
    for (int i=1; i<n; i++)
        result.add_edge(i, (i-1)/2);

    return result;
}