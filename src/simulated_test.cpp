#include "graph_simulator.cpp"
#include <ctime>

int main() {

    int type_num = -1;
    while (type_num < 0 || type_num > 3) {
        cout << "Please input the int corresponding to the type of graph you would like to test:\n" <<
        "0 - cycle graph \n1 - complete graph \n2 - empty graph \n3 - heap\n";
        cin >> type_num;
        cout << endl;
    }

    int num_nodes = -1;
    while (num_nodes < 0) {
        cout << "Please input the number of nodes you would like this graph to contain: ";
        cin >> num_nodes;
        cout << endl;
    }


    Graph<int> g;
    string g_type [4] = {"cycle graph", "complete graph", "empty graph", "heap"};

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
    cout << "CPU time to build graph: " << time_elapsed << " ms" << endl << endl;
    
    vector<vector<int*>> comps;
    vector<int*> cycle;
    vector<int*> shp;
    int op_num = -1;
    int shp1 = -1;
    int shp2 = -1;
    while (op_num < 3) {
        cout << "Please input the int corresponding to the operation you would like to run:\n" <<
        "0 - connected components  \n1 - one cycle \n2 - shortest path \n3 - exit\n";
        cin >> op_num;
        cout << endl;

        switch(op_num) {
            case 0:
                c_start = clock();
                comps = g.connected_components();
                c_end = clock();
                time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
                
                for (int i = 0; i < comps.size(); i++) {
                    for (int j = 0; j < comps[i].size(); j++)
                    cout << *comps[i][j] << " ";
                    cout << endl;
                }
                cout << endl;

                cout << "CPU time to find connected components: " << time_elapsed << " ms" << endl;
                comps.clear();
                break;
            case 1:
                c_start = clock();
                cycle = g.one_cycle();
                c_end = clock();
                time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
                
                for(int i=0; i<cycle.size(); i++)
                    cout << *cycle[i] << " ";
                cout << endl << endl;

                cout << "CPU time to find one cycle: " << time_elapsed << " ms" << endl;
                cycle.clear();
                break;
            case 2:
                while (shp1 < 0 || shp1 > num_nodes-1) {
                    cout << "Please input source node index for the shortest path opperation: ";
                    cin >> shp1;
                    cout << endl;
                }
                while (shp2 < 0 || shp2 > num_nodes-1) {
                    cout << "Please input destination node index for the shortest path opperation: ";
                    cin >> shp2;
                    cout << endl;
                }
                c_start = clock();
                shp = g.shortest_path(shp1, shp2);
                c_end = clock();
                time_elapsed = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;

                for(int i=0; i<shp.size(); i++)
                    cout << *shp[i] << " ";
                cout << endl << endl;

                cout << "CPU time to find shortest path from " << shp1 << " to " << shp2 << ": " << time_elapsed << " ms" << endl;
                shp.clear();
                break;
            default:
                break; 
        }
        cout << endl;
    }

    return 0;
}