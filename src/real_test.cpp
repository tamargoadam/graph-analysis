#include "graph_make.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please specify at least one file" << endl;
    }
    vector<string> files;

    for (int i = 1; i < argc; i++) {
        string filename(argv[i]);
        files.push_back(filename);
    }

    auto graph = buildGraph(files);

    return 0;
}