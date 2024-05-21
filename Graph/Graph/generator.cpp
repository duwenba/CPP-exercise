//
// Created by 22753 on 2024/5/21.
//
#include <Graph/Graph.h>

auto Graph::generateUndrict(int n, unsigned int randomSeed ) -> Graph {
    Matrix graph(n, std::vector<int>(n, INF)); // initialize graph with INF
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;  // set diagonal elements to 0
    }

    // generateUndrict random edges
    // set the random seed
    srand(randomSeed);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool hasEdge = rand() % 2;  // generateUndrict random boolean value
            if (hasEdge) {
                graph[i][j] = rand() % MaxValue;  // generateUndrict random weight between 0 and 99
                graph[j][i] = graph[i][j];  // set the corresponding weight for the other direction
            }
        }
    }

    return Graph(graph);
}

auto Graph::generateDirected(int n,  unsigned int randomSeed ) -> Graph {
    Matrix graph(n, std::vector<int>(n, INF)); // initialize graph with INF
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;  // set diagonal elements to 0
    }

    // generateDirected random edges
    srand(randomSeed);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!=j) {
                bool hasEdge = rand() % 2;  // generateDirected random boolean value
                if (hasEdge) {
                    graph[i][j] = rand() % MaxValue;  // generateDirected random weight between 0 and 99
                }
            }
        }
    }
    return Graph(graph);
}