#include "graph_simulator.h"

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