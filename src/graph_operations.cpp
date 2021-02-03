#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<class T>
class Graph {
  public:
    int size() {
      return adjList.size();
    }

    void add_edge(T &n1, T &n2) {
      adjList[&n1].insert(&n2);
      adjList[&n2].insert(&n1);
    }

    void print_graph()
    {
      for (auto const& pair: adjList) {
          cout << *pair.first << ": ";
          for (const auto& elem: pair.second) {
            cout << *elem << " ";
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
    unordered_map<T*, unordered_set<T *>> adjList;
};


int main() {
  Graph<int> g = Graph<int>();
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  g.add_edge(v[0], v[1]);
  g.add_edge(v[0], v[5]);
  g.add_edge(v[1], v[9]);
  g.add_edge(v[5], v[2]);
  g.add_edge(v[0], v[7]);
  g.print_graph();
  return 0;
}