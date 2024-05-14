#include <iostream>
#include <queue>
#include "spanningTree.h"

// DFS
TreeNode* dfs(const Matrix &graph, std::vector<bool> &visited, int start) {
    auto* node = new TreeNode(start);
    visited[start] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[start][i] > 0 && graph[start][i] != INF &&!visited[i]) {
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

void printTree(TreeNode *root) {
    if (root == nullptr) return;
    std::cout << root->val << "{";
    for (auto child : root->children) {
        printTree(child);
    }
    std::cout << "}, ";
}

std::vector<TreeNode *> bfsSpanningTree(const Matrix &graph) {
    std::vector<TreeNode *> spanningTree;
    std::vector<bool> visited(graph.size(), false);
    std::queue<TreeNode*> q;

    for (int i = 0; i < graph.size(); i++) {
        if (visited[i]) continue; // already visited
        auto* root = new TreeNode(i);
        q.push(root);
        visited[i] = true;
        while (!q.empty()) {
            auto* node = q.front();
            q.pop();
            for (int i = 0; i < graph.size(); i++) {
                if (graph[node->val][i] > 0 && graph[node->val][i] != INF && !visited[i]) {
                    auto* child = new TreeNode(i);
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
