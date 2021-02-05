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

int main() {
    Graph<int> g = cycle_graph(10);
    g.print_graph();

    cout << endl;

    vector<vector<int*>> comps = g.connected_components();
    for (int i = 0; i < comps.size(); i++) {
        for (int j = 0; j < comps[i].size(); j++)
        cout << *comps[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    vector<int*> cycle = g.one_cycle();
    for(int i=0; i<cycle.size(); i++)
        cout << *cycle[i] << " ";
    cout << endl << endl;

    vector<int*> shp = g.shortest_path(2, 7);
    for(int i=0; i<shp.size(); i++)
        cout << *shp[i] << " ";

    return 0;
}