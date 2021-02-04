#include "graph_simulator.h"

using namespace std;

Graph<int> n_cycle_graph(int n) {
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

int main() {
    Graph<int> g = n_cycle_graph(10);
    g.print_graph();
    return 0;
}