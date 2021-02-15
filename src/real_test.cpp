#include "real_test.h"

using namespace std;

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

    int option = -1;

    while (option != 0) {
        cout << "Real Test -- Data Loaded from " << filenames.size() << " files." << endl;

        cout << "----------------" << endl;
        cout << "[1] Adjacency Criteria 1 - \"A Mutual Interest\" - Each person rated the same movie" << endl;
        cout << "[2] Adjacency Criteria 2 - \"Hater's Club\" - Both people have given a 1 star rating to the same movie" << endl; 
        cout << "[3] Adjacency Criteria 3 - \"Trending\" - Both rated the same movie on the same day" << endl;
        cout << "   [0] Quit" << endl;
        cin >> option;

        switch (option) {
            case 0:
                return 0;
            case 1:
                graph.adjCrit1();
                break;
            case 2: 
                graph.adjCrit2();
                break;
            case 3:
                graph.adjCrit3();
                break;
            default:
                cout << "Please enter a valid option" << endl;
        }
    }

    return 0;
}