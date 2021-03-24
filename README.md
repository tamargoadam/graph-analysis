# graph-analysis

## Usage
To build the program, move into the `src` folder and run `make`. This will build two applications; *real_test* and *simulated_test*. To test for memory usage, use `env test ./simulated_test` or `env test real_test <filename>`.

`./simulated_test` allows the user to run the simulated tests as described below.

`./real_test <filename 1> <filename 2> … <filename x>` allows the user to build graphs using adjacency criteria with raw input from all of the files specified in arguments.

### Graph Implementation:
This is an adjacency list implementation of a graph. In our graph class we use the nodes vector to hold all the objects or variables (of type T) that correspond to a node. The adj_list vector contains one vector per row. The integers held in the vector at index i of adj_list, correspond to the indices of nodes that are neighbors to nodes[i], in the nodes vector.

### Graph Operations:

##### connected_components():
To find all connected components in the graph, iterative depth first search is utilized. A stack is used to perform the iterative depth first search, a set, not_found, is used to quickly check if all nodes have been found or if there is another connected component to be traversed, and a visited vector is used to hold a flag per node indicating if the node has been previously visited to prevent duplicates from being added to our resulting connected component.

##### one_cycle():
Iterative depth first search is also used to find and return one cycle from the graph if a cycle exists. As stated above, iterative depth first search makes use of a stack; however, this operation holds a pair representing two nodes, the node visited and the previous node on the path to that node. This allows us to retrace our steps when we find a potential cycle. Also as seen above, we use a set, not_found, to protect against the case that a cycle was not found in the first connected component but may exist in an untraversed component. In addition to these, we use a vector, cur_path, to track the path that we have covered so far, excluding nodes that lead to dead ends previously.

##### shortest_path():
To implement Dijkstra’s shortest path algorithm on our graph, we traverse the graph using breadth first search which requires a queue. In addition to the queue, we use a vector, last_visited, to hold the indices of the last visited node on the shortest distance path found so far for each node. This vector allows us to trace backwards and report our paths back to the source node when the algorithm has completed. We also use a vector, distances to track the distance of the shortest path from the source node found so far. This is checked against when a node is revisited to ensure that the current path to that node is still shortest.

### File Format
real_test uses adjacency criteria meant to be run on data constructed to support participants in the [Netflix Prize](http://www.netflixprize.com) competition. The ratings data was provided in the following format:

```
MovieID1:
CustomerID11,Rating,Date11
CustomerID12,Rating,Date12
...
MovieID2:
CustomerID21,Rating,Date21
CustomerID22,Rating,Date22
```
