#include <Graph/graph.h>
#include <iostream>
#include <ctime>



int main() {
    int countOfNodes = 10; // Set the number of nodes in the graph

    auto graph = Graph::generateDirected(countOfNodes); // Generate a graph

    std::cout << "Graph:\n";
    graph.PrintMatrix(); // Print the graph
    std::cout << "\n";
    graph.Dijkstra(0); // Find the shortest path from node 0

    graph.Floyd();

    return 0;
}