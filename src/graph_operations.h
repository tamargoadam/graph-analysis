#include <vector>
#include <unordered_map>
#include <unordered_set>

template<typename T>
class Graph {
  public:
    int size();
    void add_edge(T &n1, T &n2);
    void print_graph();
    std::vector<std::vector<T*>> connected_components();
    std::vector<T*> one_cycle();
    std::vector<T*> shortest_path(T &src, T &dest);

  private:
    std::unordered_map<T*, std::unordered_set<T *>> adj_list;
};