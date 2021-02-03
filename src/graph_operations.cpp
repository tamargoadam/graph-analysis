#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


template<class T>
class Graph {
  public:

    int numNodes;
    unordered_map<T*, vector<T *>> adjList;

    Graph() {
      numNodes=0;
    }

    void add_edge_undir(T &n1, T &n2) {
      add_edge(n1, n2);
      add_edge(n2, n1);
    }

    void print_graph()
    {
      for (auto const& pair: adjList) {
          cout << *pair.first << ": ";
          for (auto const& val: pair.second) {
            cout << *val << " ";
          }
          cout << endl;
      }
    }

    // vector<int> connected_components(Graph<T> g) {
    //   bool* visited = new bool[numNodes];
    //   for(int i=0; i<numNodes; i++) {
        
    //   }
    // }

  private:
    void add_edge(T &n1, T &n2) {
      if (adjList.find(&n1) != adjList.end()) {
        // adjList.insert(make_pair(&n1, vector<T *>()));
        adjList[&n1] = vector<T *>();
      }
      adjList[&n1].push_back(&n2);
    }
};


int main() {
  Graph<int> g = Graph<int>();
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  g.add_edge_undir(v[0], v[1]);
  g.add_edge_undir(v[0], v[5]);
  g.print_graph();
  return 0;
}