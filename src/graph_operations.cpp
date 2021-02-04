#include <iostream>
#include <vector>
#include <list>
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
        conn_comps.clear();
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

    vector<T*> one_cycle() {
      unordered_map<T*, bool> visited;
      unordered_set<T *> not_found;
      stack<T*> stack;
      vector<T*> cur_path; // track potential cycle
      vector<T*> cycle; 
      T* s;
      T* last;

      for (auto const& pair: adj_list) {
          visited[pair.first] = false;
          not_found.insert(pair.first);
      }

      while(not_found.size() > 0) {
        stack.push(*not_found.begin());
        cur_path.clear();

        while (!stack.empty()) {
          s = stack.top();
          stack.pop();

          if (!visited[s]) {
              cur_path.push_back(s);
              visited[s] = true;
              not_found.erase(s);
          }

          bool next = false;
          bool start_c = false;
          for (const auto& i: adj_list[s]) {
            if (visited[i]) {
              if(i != last) {
                for(const auto& j: cur_path) {
                  if(j == i)
                    start_c = true;
                  if(start_c)
                    cycle.push_back(j);
                }
                cycle.push_back(i);
                return cycle;
              }
            }
            else {
              stack.push(i);
              next = true;
            }
          }
          if (!next)
            cur_path.pop_back();
          last = s;
        }
      }
      return vector<T*>();
    }

    vector<T*> shortest_path(T &src, T &dest) {
      unordered_map<T*, T*> last_visited;
      unordered_map<T*, int> distances;
      list<T*> queue;
      T* cur;
      vector<T*> path;

      for (auto const& pair: adj_list)
          distances[pair.first] = -1;
 
      distances[&src] = 0;
      queue.push_back(&src);
 
      while(!queue.empty()) {
        cur = queue.front();
        queue.pop_front();
 
        for (auto i = adj_list[cur].begin(); i != adj_list[cur].end(); ++i) {
          if (distances[*i] < 0 || distances[*i] > distances[cur]+1) {
            distances[*i] = distances[cur]+1;
            last_visited[*i] = cur;
            queue.push_back(*i);
          }
        }
      }

      if (distances.find(&dest)!=distances.end()){
        T* cur = &dest;
        path.push_back(cur);
        while(true) {
          path.push_back(last_visited[cur]);
          // cout << *cur << endl;
          cur = last_visited[cur];
          if (last_visited[cur] == &src)
            return path;
        }
      }
      return vector<T*>();
    }

  private:
    unordered_map<T*, unordered_set<T *>> adj_list;
};


int main() {
  Graph<int> g = Graph<int>();
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  g.add_edge(v[0], v[1]);
  g.add_edge(v[0], v[5]);
  g.add_edge(v[0], v[2]);
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
  cout << endl;

  vector<int*> cycle = g.one_cycle();
  for(int i=0; i<cycle.size(); i++)
    cout << *cycle[i] << " ";
  cout << endl << endl;

  vector<int*> shp = g.shortest_path(v[0], v[8]);
  for(int i=0; i<shp.size(); i++)
    cout << *shp[i] << " ";

  return 0;
}