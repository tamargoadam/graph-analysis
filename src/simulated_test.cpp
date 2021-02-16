#include "graph_simulator.cpp"
#include <sys/time.h> 

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

    struct timeval t1, t2;
    double time_elapsed;

    gettimeofday(&t1, NULL);
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
    gettimeofday(&t2, NULL);
    time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    time_elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    cout << "CPU time to build graph: " << time_elapsed << " ms" << endl << endl;
    
    vector<vector<int*>> comps;
    vector<int*> cycle;
    vector<vector<int*>> shp;
    int op_num = -1;
    int shp1 = -1;
    while (op_num < 3) {
        cout << "Please input the int corresponding to the operation you would like to run:\n" <<
        "0 - connected components  \n1 - one cycle \n2 - shortest path \n3 - exit\n";
        cin >> op_num;
        cout << endl;

        switch(op_num) {
            case 0:
                gettimeofday(&t1, NULL);
                comps = g.connected_components();
                gettimeofday(&t2, NULL);
                time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
                time_elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
                
                if (num_nodes < 100000) {
                    for (int i = 0; i < comps.size(); i++) {
                        for (int j = 0; j < comps[i].size(); j++)
                        cout << *comps[i][j] << " ";
                        cout << endl;
                    }
                }
                else {
                    cout << "Connected components found.";
                }
                cout << endl;

                cout << "CPU time to find connected components: " << time_elapsed << " ms" << endl;
                comps.clear();
                break;
            case 1:
                gettimeofday(&t1, NULL);
                cycle = g.one_cycle();
                gettimeofday(&t2, NULL);
                time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
                time_elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
                
                if (cycle.size() < 100000) {
                    for(int i=0; i<cycle.size(); i++)
                        cout << *cycle[i] << " ";
                    cout << endl << endl;
                }
                else {
                    cout << "Cycle found." << endl;
                }

                cout << "CPU time to find one cycle: " << time_elapsed << " ms" << endl;
                cycle.clear();
                break;
            case 2:
                while (shp1 < 0 || shp1 > num_nodes-1) {
                    cout << "Please input source node index for the shortest path opperation: ";
                    cin >> shp1;
                    cout << endl;
                }
                gettimeofday(&t1, NULL);
                shp = g.shortest_path(shp1);
                gettimeofday(&t2, NULL);
                time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
                time_elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms

                if (num_nodes <= 1000) {
                    for(int i=0; i<shp.size(); i++) {
                        for(int j=0; j<shp[i].size(); j++)
                            cout << *shp[i][j] << " ";
                        cout << endl;
                    }
                }
                else {
                    cout << "Shortest path found if present.";
                }
                cout << endl;

                cout << "CPU time to find shortest path to all connected nodes from " << shp1 << ": " << time_elapsed << " ms" << endl;
                shp.clear();
                shp1 = -1;
                break;
            default:
                break; 
        }
        cout << endl;
    }

    return 0;
}