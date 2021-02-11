#include "graph_simulator.cpp"
#include <ctime>

int main() {

    Graph<int> g;
    string g_type [4] = {"cycle graph", "complete graph", "empty graph", "heap"};

    for (int type_num = 0; type_num < 4; type_num++){
        for (int num_nodes = 10; num_nodes <= 1000; num_nodes=num_nodes*10){
            
            cout << "GRAPH: " << g_type[type_num] << endl;
            cout << "NUM NODES: " << num_nodes << endl << endl;

            clock_t c_start = clock();
            switch(type_num) {
                case 0:
                    g = cycle_graph(num_nodes);
                    break;
                case 1:
                    g = complete_graph(num_nodes);
                    break;
                case 2:
                    g = empty_graph(num_nodes);
                    break;
                default:
                    g = heap(num_nodes);
                    break;
            }
            clock_t c_end = clock();
            long double time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
            cout << "CPU time to build graph: " << time_elapsed << " ms" << endl;
            
            c_start = clock();
            vector<vector<int*>> comps = g.connected_components();
            c_end = clock();
            time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
            cout << "CPU time to find connected components: " << time_elapsed << " ms" << endl;
            // for (int i = 0; i < comps.size(); i++) {
            //     for (int j = 0; j < comps[i].size(); j++)
            //     cout << *comps[i][j] << " ";
            //     cout << endl;
            // }
            // cout << endl;

            c_start = clock();
            vector<int*> cycle = g.one_cycle();
            c_end = clock();
            time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
            cout << "CPU time to find one cycle: " << time_elapsed << " ms" << endl;
            // for(int i=0; i<cycle.size(); i++)
            //     cout << *cycle[i] << " ";
            // cout << endl << endl;

            c_start = clock();
            vector<int*> shp = g.shortest_path(num_nodes/5, num_nodes*2/3);
            c_end = clock();
            time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
            cout << "CPU time to find shortest path from " << num_nodes/5 << " to " << num_nodes*2/3 << ": " << time_elapsed << " ms" << endl;
            // for(int i=0; i<shp.size(); i++)
            //     cout << *shp[i] << " ";
            // cout << endl << endl;

            cout << endl; 

        }
    }

    return 0;
}