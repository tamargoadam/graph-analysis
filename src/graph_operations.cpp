#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;


template<class T>
class Graph {
  public:
    int size() {
      return adj_list.size();
    }

    void add_edge(T &n1, T &n2) {
      adj_list[&n1].insert(&n2);
      adj_list[&n2].insert(&n1);
    }

    void print_graph()
    {
      for (auto const& pair: adj_list) {
          cout << *pair.first << ": ";
          for (const auto& elem: pair.second) {
            cout << *elem << " ";
          }
          cout << endl;
      }
    }

    vector<vector<T*>> connected_components() {
      unordered_map<T*, bool> visited;
      unordered_set<T *> not_found;
      stack<T*> stack;
      vector<vector<T*>> result;
      vector<T*> conn_comps;
      T* s;

      for (auto const& pair: adj_list) {
          visited[pair.first] = false;
          not_found.insert(pair.first);
      }

      while(not_found.size() > 0) {
        stack.push(*not_found.begin());

        while (!stack.empty()) {
          s = stack.top();
          stack.pop();

          if (!visited[s]) {
              conn_comps.push_back(s);
              visited[s] = true;
              not_found.erase(s);
          }

          for (const auto& i: adj_list[s]) {
            if (!visited[i])
              stack.push(i);
          }
        }
        result.push_back(conn_comps);
      }
      return result;
    }

    // DFS for reference
    vector<T*> dfs_util() {
      unordered_map<T*, bool> visited;
      stack<T*> stack;
      vector<T*> result;
      T* s;

      for (auto const& pair: adj_list) {
          visited[pair.first] = false;
      }
      stack.push((*adj_list.begin()).first);

      while (!stack.empty()) {
        s = stack.top();
        stack.pop();

        if (!visited[s]) {
            result.push_back(s);
            visited[s] = true;
        }

        for (const auto& i: adj_list[s]) {
          if (!visited[i])
            stack.push(i);
        }
      }
      return result;
    }

  private:
    unordered_map<T*, unordered_set<T *>> adj_list;
};


int main() {
  Graph<int> g = Graph<int>();
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  g.add_edge(v[0], v[1]);
  g.add_edge(v[0], v[5]);
  g.add_edge(v[1], v[9]);
  g.add_edge(v[5], v[2]);
  g.add_edge(v[3], v[8]);
  g.add_edge(v[0], v[7]);
  g.print_graph();
  
  cout << endl;

  vector<vector<int*>> comps = g.connected_components();
  for (int i = 0; i < comps.size(); i++) {
    for (int j = 0; j < comps[i].size(); j++)
      cout << *comps[i][j] << " ";
    cout << endl;
  }
  return 0;
}