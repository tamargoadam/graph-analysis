#pragma once

#ifndef GRAPH_OPS_H
#define GRAPH_OPS_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include "net_node.cpp"

using namespace std;

template<typename T>
class Graph {
  public:
    int size();
    void load_nodes(std::vector<T> n);
    void add_edge(int ind1, int ind2);
    void clear_edges();
    void print_graph();
    std::vector<std::vector<T*>> connected_components();
    std::vector<T*> one_cycle();
    std::vector<T*> shortest_path(int src_ind, int dest_ind);


    ~Graph();

    void adjCrit1();
    void adjCrit2();
    void adjCrit3();

  private:
    // std::unordered_map<T*, std::unordered_set<T *>> adj_list;
    std::vector<std::vector<int>> adj_list;
    std::vector<T> nodes;

};
#endif