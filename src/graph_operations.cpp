#include "graph_operations.h"

using namespace std;


template<typename T>
void Graph<T>::load_nodes(vector<T> n) {
  nodes = n;
  for(int i=0; i<nodes.size(); i++) {
    adj_list.push_back(vector<int>());
  }
};

template<typename T>
void Graph<T>::add_edge(int ind1, int ind2) {
  adj_list[ind1].push_back(ind2);
  adj_list[ind2].push_back(ind1);
}

template<typename T>
void Graph<T>::clear_edges() {
  this->adj_list = vector<vector<int>>();
}

template<typename T>
void Graph<T>::print_graph()
{
  for (int i=0; i<adj_list.size(); i++) {
    cout << nodes[i] << ": ";
    for (int j=0; j<adj_list[i].size(); j++) {
      cout << nodes[adj_list[i][j]] << " ";
    }
    cout << endl;
  }
}

template<typename T>
vector<vector<T*>> Graph<T>::connected_components() {
  vector<bool> visited = vector<bool>(nodes.size());
  unordered_set<int> not_found;
  stack<int> stack;
  vector<vector<T*>> result;
  vector<T*> conn_comps;
  int s;

  for (int i=0; i<nodes.size(); i++) {
      visited.push_back(false);
      not_found.insert(i);
  }

  while(not_found.size() > 0) {
    conn_comps.clear();
    stack.push(*not_found.begin());

    while (!stack.empty()) {
      s = stack.top();
      stack.pop();

      if (!visited[s]) {
          conn_comps.push_back(&nodes[s]);
          visited[s] = true;
          not_found.erase(s);
      }

      for (int i=0; i<adj_list[s].size(); i++) {
        if (!visited[adj_list[s][i]])
          stack.push(adj_list[s][i]);
      }
    }
    result.push_back(conn_comps);
  }
  return result;
}

template<typename T>
vector<T*> Graph<T>::one_cycle() {
  vector<bool> visited = vector<bool>(nodes.size(), false);
  unordered_set<int> not_found;
  stack<pair<int, int>> stack;
  vector<int> cur_path;
  vector<T*> cycle; 
  int s, f;

  for (int i=0; i<nodes.size(); i++)
      not_found.insert(i);

  while(not_found.size() > 0) {
    stack.push(make_pair(*not_found.begin(), -1));
    cur_path.clear();

    while (!stack.empty()) {
      s = stack.top().first;
      f = stack.top().second;
      stack.pop();

      if (!visited[s]) {
          cur_path.push_back(s);
          visited[s] = true;
          not_found.erase(s);
      }

      bool next = false;
      bool start_c = false;
      for (int i=0; i<adj_list[s].size(); i++) {
        int n = adj_list[s][i];
        if (visited[n]) {
          if(n != f) {
            for(int j=0; j<cur_path.size(); j++) {
              if(cur_path[j] == n)
                start_c = true;
              if(start_c) {
                cycle.push_back(&nodes[cur_path[j]]);
              }
            }
            cycle.push_back(&nodes[n]);
            return cycle;
          }
        }
        else {
          stack.push(make_pair(n, s));
          next = true;
        }
      }
      if (!next)
        cur_path.pop_back();
    }
  }
  return vector<T*>();
}

template<typename T>
vector<vector<T*>> Graph<T>::shortest_path(int src_ind) {
  vector<int> last_visited = vector<int>(nodes.size(), -1);
  vector<int> distances = vector<int>(nodes.size(), -1);
  list<int> queue;
  int cur;
  vector<vector<T*>> sp;


  distances[src_ind] = 0;
  queue.push_back(src_ind);

  while(!queue.empty()) {
    cur = queue.front();
    queue.pop_front();


    for (int i=0; i<adj_list[cur].size(); i++) {
      int n = adj_list[cur][i];
      if (distances[n] < 0 || distances[n] > distances[cur]+1) {
        distances[n] = distances[cur]+1;
        last_visited[n] = cur;
        queue.push_back(n);
      }
    }
  }

  for (int i=0; i<nodes.size(); i++) {
    if (distances[i]!=-1 && i!=src_ind){
      int n = i;
      sp.push_back(vector<T*>());
      sp[sp.size()-1].push_back(&nodes[n]);
      while(last_visited[n] != -1) {
        sp[sp.size()-1].push_back(&nodes[last_visited[n]]);
        n = last_visited[n];
      }
    }
  }
  return sp;
}

template<typename T>
Graph<T>::~Graph() {}

template<>
Graph<netNode*>::~Graph() {
  for (auto n : this->nodes) {
    delete n;
  }
}

template<typename T>
void Graph<T>::adjCrit1() {
    cout << "Function only intended for graphs of type netNode*" << endl;
}

template<typename T>
void Graph<T>::adjCrit2() {
    cout << "Function only intended for graphs of type netNode*" << endl;
}

template<typename T>
void Graph<T>::adjCrit3() {
    cout << "Function only intended for graphs of type netNode*" << endl;
}


// Adds an edge between any two nodes that share a movie and both have a rating over 3 stars
template<>
void Graph<netNode*>::adjCrit1() {
  this->clear_edges();

  int numEdges = 0;
  cout << "Starting Adj Crit 1 ..." << endl;
  cout << this->nodes.size() << endl;
  clock_t start = clock(); 

  for (int i = 0; i < this->nodes.size(); i++) {
    for (int j = i+1; j < this->nodes.size(); j++) {
      if (i%1000 == 0 || j%1000 == 0) cout << i << " " << j << endl;
      for (auto it = nodes[i]->ratings.begin(); it != nodes[i]->ratings.end(); it++) {
        if ((it->second).first > 3) {
          if (nodes[j]->ratings.find(it->first) != nodes[j]->ratings.end() && (nodes[j]->ratings[it->first]).first > 3) {
            this->add_edge(i, j);
            numEdges++;
          } 
        }
      }
    }
  }
  clock_t tot = clock() - start;
  cout << "Operation completed. Added " << numEdges << " in " << tot << endl;
}

//
template<>
void Graph<netNode*>::adjCrit2() {
  this->clear_edges();
  for(int i = 0; i < this->nodes.size(); i++) {
    for (int j = i+1; j < this->nodes.size(); j++) {
      for (auto it = nodes[i]->ratings.begin(); it != nodes[i]->ratings.end(); it++) {
        if ((it->second).first == 1) {
          if (nodes[j]->ratings.find(it->first) != nodes[j]->ratings.end() && nodes[j]->ratings[it->first].first> 3) {
            this->add_edge(i, j);
          } 
        }
      }
    }
  }
}

template<>
void Graph<netNode*>::adjCrit3() {
  this->clear_edges();
  for(int i = 0; i < this->nodes.size(); i++) {
    for (int j = i+1; j < this->nodes.size(); j++) {
      for (auto it = nodes[i]->ratings.begin(); it != nodes[i]->ratings.end(); it++) {
        auto f = nodes[j]->ratings.find(it->first);
        if(f != nodes[j]->ratings.end()) {
          if ((f->second).second == (it->second).second) {
            this->add_edge(i, j);
          }
        }
      }
    }
  }
}
