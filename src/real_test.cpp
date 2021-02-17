#include "real_test.h"

using namespace std;


void graphOperationsMenu(Graph<netNode*>& graph) {
    int option = -1;

    int numComponents = -1;
    clock_t tot;
    vector<int> componentSizes;

    cout << "Running Connected Components... " << endl;

    clock_t start = clock();
    auto c = graph.connected_components();
    tot = clock()-start;

    numComponents = c.size();

    for (auto e : c) {
        componentSizes.push_back(e.size());
    }

    cout << "Number of Connected Components: " << c.size() << endl;
    cout << "Finished in " << tot << "ms" << endl;

    while (option != 0) {
        cout << "Graph Operations" << endl;

        cout << "----------------" << endl;
        cout << "[1] Run Connected Components" << endl;
        cout << "[2] Print number of Components (must run [1] first)" << endl;
        cout << "[3] Print component sizes (must run [1] first)" << endl;
        cout << "   [0] Dispose of graph, return to previous menu" << endl;
        cin >> option;

        


        switch (option) {
            case 0:
                graph.clear_edges();
                return;
                break;
            case 1: 
                cout << "Running Connected Components... " << endl;

                start = clock();
                c = graph.connected_components();
                tot = clock()-start;

                numComponents = c.size();

                for (auto e : c) {
                    componentSizes.push_back(e.size());
                }

                cout << "Number of Connected Components: " << c.size() << endl;
                cout << "Finished in " << tot << "ms" << endl;


            
                break;
            case 2:
                cout << "Number of Connected Components: " << numComponents << endl;
                break;
            case 3:
                cout << "Component Sizes:" << endl;
                for (auto v : componentSizes) {
                    cout << "\t" << v << endl;
                }
            case 4:
                cout << "Execution Time" << endl;
                cout << "Connected Components Finished in " << tot << "ms" << endl;


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
        cout << "[1] Adjacency Criteria 1 - \"Hater's Club\" - Both people have given a 1 star rating on the same movie for at least 3 movies" << endl; 
        cout << "[2] Adjacency Criteria 2 - \"Trending\" - Both rated the same movie 5 stars on the same day" << endl;
        cout << "[3] Adjacency Criteria 3 - \"Great Minds\" - Sort users by average rating, connect in order to form a Doubly-Linked-List in order. " << endl;
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

