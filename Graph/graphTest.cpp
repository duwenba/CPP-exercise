#include <iostream>
#include "Graph/graph.h"


void restVisitedVec(vector<bool>& visited) {
    for (auto each : visited) {
        each = false;
    }
}

void printVec(vector<int>& vec) {
    for (auto each : vec) {
        cout << each << " ";
    }
    cout << endl;
}


int main() {
    //邻接矩阵表示的图
    /**   \note 邻接表表示的图 \n
     *    0 -> 1     \n
     *    1 -> 0 -> 2 -> 3 -> 4   \n
     *    2 -> 1 -> 3  \n
     *    3 -> 1 -> 2 -> 4  \n
     *    4 -> 1 -> 3  \n
     */
    vector<vector<int>> graphMatrix = {
        {0, 1, 0, 0, 0}, // 0
        {1, 0, 1, 1, 1}, // 1
        {0, 1, 0, 1, 0}, // 2
        {0, 1, 1, 0, 1}, // 3
        {0, 1, 0, 1, 0}  // 4
    };
    int n = 5;

    // Create a graph
    Graph g;
    g.fromMatrix(n, graphMatrix);

    // Print the graph
    auto visited = vector<bool>(n, false);
    cout << "DFS traversal of the graph:\n";
    g.dfs(0, visited);
    cout << endl;
    // BFS traversal of the graph
    cout << "BFS traversal of the graph:\n";
    g.bfs(0);
    cout << endl;

    //重置visited数组
    restVisitedVec(visited);

    // hasPath function
    cout << "Does graph have a path from 0 to 3? \n"
         << (g.hasPath(0, 3, visited)? "Yes" : "No") << endl;

    // findAllPaths function
    cout << "Find all paths from 0 to 3:\n";
    restVisitedVec(visited);
    auto paths = g.findAllPaths(0, 3, visited);
    for (auto path: paths) {
        printVec(path);
    }

    return 0;
}
