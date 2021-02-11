#ifndef GRAPH_SIM_H
#define GRAPH_SIM_H

#include "graph_operations.cpp"

#include <iostream>
#include <vector>

Graph<int> cycle_graph(int n);
Graph<int> complete_graph(int n);
Graph<int> empty_graph(int n);
Graph<int> heap(int n);

#endif