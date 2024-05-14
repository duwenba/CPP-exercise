#include <iostream>
#include <queue>
#include "spanningTree.h"

// DFS
TreeNode *dfs(const Matrix &graph, std::vector<bool> &visited, int start) {
    auto *node = new TreeNode(start);
    visited[start] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[start][i] > 0 && graph[start][i] != INF && !visited[i]) {
            node->children.push_back(dfs(graph, visited, i));
        }
    }
    return node;
}


// DFS algorithm to find a spanning tree of a graph
std::vector<TreeNode *> dfsSpanningTree(const Matrix &graph) {
    std::vector<TreeNode *> spanningTree;
    std::vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i]) continue; // already visited
        spanningTree.push_back(dfs(graph, visited, i));
    }
    return spanningTree;
}

void printTree(TreeNode *root, bool first) {
    if (root == nullptr) return;
    std::cout << root->val << "{ ";
    for (auto child: root->children) {
        printTree(child, false);
    }
    std::cout << "}";
    if (!first) std::cout << ", ";
}

std::vector<TreeNode *> bfsSpanningTree(const Matrix &graph) {
    std::vector<TreeNode *> spanningTree;
    std::vector<bool> visited(graph.size(), false);
    std::queue<TreeNode *> q;

    for (int i = 0; i < graph.size(); i++) {
        if (visited[i]) continue; // already visited
        auto *root = new TreeNode(i);
        q.push(root);
        visited[i] = true;
        while (!q.empty()) {
            auto *node = q.front();
            q.pop();
            for (int i = 0; i < graph.size(); i++) {
                if (graph[node->val][i] > 0 && graph[node->val][i] != INF && !visited[i]) {
                    auto *child = new TreeNode(i);
                    node->children.push_back(child);
                    q.push(child);
                    visited[i] = true;
                }
            }
        }
        spanningTree.push_back(root);
    }
    return spanningTree;

}

void primSpanningTree(const Matrix &graph, int start) {

    auto lowCost = std::vector<int>(graph.size(), INF);
    lowCost[start] = 0;
    auto closest = std::vector<int>(graph.size(), -1);

    int min, closeIndex;

    for (int i = 0; i < graph.size(); i++) {
        lowCost[i] = graph[start][i];
        closest[i] = start;
    }
    printf("Prim Spanning Tree:\n %d ", start);
    for (int i = 1; i < graph.size() - 1; i++) {

        // 找到当前最小权值的边
        min = INF;
        for (int j = 0; j < graph.size(); j++) {
            if (lowCost[j] != 0 && lowCost[j] < min) {
                min = lowCost[j];
                closeIndex = j;
            }
        }

        printf("--%d--> %d ", min, closeIndex);
        lowCost[closeIndex] = 0; // 标记为已访问

        // 更新相邻节点的权值
        for (int j = 0; j < graph.size(); j++) {
            if (graph[closeIndex][j] != 0 && graph[closeIndex][j] < lowCost[j]) {
                lowCost[j] = graph[closeIndex][j];
                closest[j] = closeIndex;
            }
        }
    }

}
