#include "real_test.h"

using namespace std;


void graphOperationsMenu(Graph<netNode*>& graph) {
    int option = -1;
    while (option != 0) {
        cout << "Graph Operations" << endl;

        cout << "----------------" << endl;
        cout << "[1] Connected Components" << endl;
        cout << "   [0] Dispose of graph, return to previous menu" << endl;
        cin >> option;


        switch (option) {
            case 0:
                graph.clear_edges();
                return;
            case 1: {
                cout << "Running Connected Components... " << endl;

                clock_t start = clock();
                auto connComps = graph.connected_components();
                clock_t tot = clock()-start;

                cout << "Finished in " << tot << "ms" << endl;
                cout << "Number of Connected Components: " << connComps.size() << endl;

                cout << "Component Sizes:" << endl;
                for (auto v : connComps) {
                    cout << "\t" << v.size() << endl;
                }
            }
                break;
            

            default:
                cout << "Please enter a valid option" << endl;
                break;
        }
    }
}

void buildGraphMenu(Graph<netNode*>& graph) {
    int option = -1;
    while (option != 0) {

        cout << "----------------" << endl;
        cout << "[1] Adjacency Criteria 1 - \"A Mutual Interest\" - Each person rated the same movie" << endl;
        cout << "[2] Adjacency Criteria 2 - \"Hater's Club\" - Both people have given a 2 star rating or lower on the same movie for at least 3 movies" << endl; 
        cout << "[3] Adjacency Criteria 3 - \"Trending\" - Both rated the same movie on the same day" << endl;
        cout << "   [0] Quit" << endl;
        cin >> option;

        switch (option) {
            case 0:
                return;
            case 1:
                graph.adjCrit1();
                graphOperationsMenu(graph);
                break;
            case 2: 
                graph.adjCrit2();
                graphOperationsMenu(graph);

                break;
            case 3:
                graph.adjCrit3();
                graphOperationsMenu(graph);
                break;
            default:
                cout << "Please enter a valid option" << endl;
                break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please specify at least one file" << endl;
    }
    vector<string> filenames;

    for (int i = 1; i < argc; i++) {
        string f(argv[i]);
        filenames.push_back(f);
    } 
    
    Graph<netNode*> graph = buildGraph(filenames);

    cout << "Real Test -- Data Loaded from " << filenames.size() << " files." << endl;


    buildGraphMenu(graph);
    

    return 0;
}

