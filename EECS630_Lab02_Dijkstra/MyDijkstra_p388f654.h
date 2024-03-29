#ifndef _MY_DIJKSTRA_H_
#define _MY_DIJKSTRA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
#include <utility>

typedef unsigned int NodeType;
typedef unsigned int WeightType;
typedef std::vector<std::vector<std::pair<NodeType, WeightType>>> GraphType; // graph as adjacent list

/*------------------------------------------------------------------------------
 ShortestPath_Dijkstra
  Find and print the shortest path from source to end using the Dijkstra's algorithm

 Vairables:
   - graph: the input graph
   - source: the source node
   - end: the target node
   - path_len: the the summation of weights of all edges in the shortest path
   - path: the shortest path represented as a list of nodes

------------------------------------------------------------------------------*/
void ShortestPath_Dijkstra(
    const GraphType& graph,
    const NodeType & source,
    const NodeType & end,
    WeightType & path_len,
    std::vector<NodeType> & path)
{
  /*------ CODE BEGINS ------*/
   // Initialize the distance to all nodes as infinite and the previous node as undefined
    //The code snippet `std::vector<WeightType> dist(graph.size(), UINT_MAX);` is initializing a vector named `dist` with the size equal to the number of nodes in the graph. Each element in this vector represents the distance from the source node to the corresponding node in the graph. Initially, all distances are set to `UINT_MAX`, indicating that the distances are unknown or infinite.
    std::vector<WeightType> dist(graph.size(), UINT_MAX);
    std::vector<NodeType> prev(graph.size(), UINT_MAX);

    // Create a priority queue to store nodes that are being preprocessed
    std::priority_queue<std::pair<WeightType, NodeType>, std::vector<std::pair<WeightType, NodeType>>, std::greater<std::pair<WeightType, NodeType>>> pq;

    //This part of the code is implementing the main logic of Dijkstra's algorithm for finding the shortest path in a graph from a source node to a target node. Here's a breakdown of what each step is doing:
    // Distance of the source node from itself is always 0
    dist[source] = 0;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        NodeType u = pq.top().second;
        pq.pop();

        // Visit all adjacent nodes of u
        for (auto& edge : graph[u]) {
            NodeType v = edge.first;
            WeightType weight = edge.second;

            // Relaxation step
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }

    // Check if there is a path from source to end
    // This part of the code is checking if there exists a path from the source node to the target node (end) in the graph.
    if (dist[end] == UINT_MAX) {
        path_len = UINT_MAX;
        path.clear();
        return;
    }

    // Reconstruct the path from source to end
    path_len = dist[end];
    std::stack<NodeType> s;
    for (NodeType at = end; at != UINT_MAX; at = prev[at]) {
        s.push(at);
    }

    // Store the path in the vector
    path.clear();
    while (!s.empty()) {
        path.push_back(s.top());
        s.pop();

  /*------ CODE ENDS ------*/
}
}



#endif
