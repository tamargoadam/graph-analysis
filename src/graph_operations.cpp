#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  vector<Node *> adjList; 
  Node(int v) {
    val = v;
  }
  void addNeighbor(Node * n) {
    adjList.push_back(n);
  }
};
 
class Graph {
  public:
    // int numNodes; Redundant variable -- simply use nodes.size();
    // Works as long as the Graph constructor has been called. 
    vector<Node *> nodes;
    Graph() {
    }

    const int Graph::numNodes() {
      return nodes.size();
    }
};

vector<int> connected_components(Graph g) {
  int numNodes = g.nodes.size();
  bool* visited = new bool[numNodes];
  for(int i=0; i<numNodes; i++) {
    
  }
}

int main() {
  return 0;
}