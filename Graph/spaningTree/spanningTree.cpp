#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
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
            for (int j = 0; j < graph.size(); j++) {
                if (graph[node->val][j] > 0 && graph[node->val][j] != INF && !visited[j]) {
                    auto *child = new TreeNode(j);
                    node->children.push_back(child);
                    q.push(child);
                    visited[j] = true;
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

    int min, closeIndex, totalCost = 0;

    for (int i = 0; i < graph.size(); i++) {
        lowCost[i] = graph[start][i];
        closest[i] = start;
    }
//    printf("Prim Spanning Tree:\n %d ", start);
    for (int i = 1; i < graph.size(); i++) {

        // 找到当前最小权值的边
        min = INF;
        for (int j = 0; j < graph.size(); j++) {
            if (lowCost[j] != 0 && lowCost[j] < min) {
                min = lowCost[j];
                closeIndex = j;
            }
        }

        printf("(%d, %d) weight: %d\n", closest[closeIndex], closeIndex, min);
        totalCost += min;

        lowCost[closeIndex] = 0; // 标记为已访问

        // 更新相邻节点的权值
        for (int j = 0; j < graph.size(); j++) {
            if (graph[closeIndex][j] != 0 && graph[closeIndex][j] < lowCost[j]) {
                lowCost[j] = graph[closeIndex][j];
                closest[j] = closeIndex;
            }
        }
    }

    std::cout << "Prim Spanning Tree total cost: " << totalCost << std::endl;
}

auto kruskalSpanningTree(const Matrix &graph) -> void {
    // 联通分量编号, 用来判断两个节点是否属于同一联通分量, 初始每个节点都属于一个联通分量
    auto vSet = [&graph]() {
        std::vector<int> vSet(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            vSet[i] = i;
        }
        return vSet;
    }();
    auto edgeSet = std::vector<Edge>(); // 边集
    int edgeNum = 0; // 边数
    int totalCost = 0; // 最小生成树的权值

    // 初始化edgeSet
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); ++j) {
            if (graph[i][j] != 0 && graph[i][j] != INF && i < j) {
                // 无向图, 边(i,j)和边(j,i)只需保留一个
                edgeSet.push_back(Edge{i, j, graph[i][j]});
                edgeNum++;
            }
        }
    }
    // 排序边集, 按权值从小到大排序
    auto comp = [](const Edge &a, const Edge &b) { return a.w < b.w; };
    std::sort(edgeSet.begin(), edgeSet.end(), comp);
    // 最小生成树
    int curEdgeNum = 1; // 当前边数
    int curEdgeIndex = 0; // 当前边索引
    while (curEdgeNum < graph.size()) {
        auto &edge = edgeSet[curEdgeIndex++];
        if (vSet[edge.u] != vSet[edge.v]) {// 边(u,v)不属于同一联通分量
            //打印边
            std::cout << "(" << edge.u << ", " << edge.v << ") weight: " << edge.w << std::endl;
            totalCost += edge.w;

            // 合并联通分量
            // 暂时存储vSet[edge.v]的值, 因为vSet[edge.v]的值会改变
            int vIdU = vSet[edge.u];
            for (int i = 0; i < edgeNum; ++i) {
                if (vSet[i] == vIdU) {
                    vSet[i] = vSet[edge.v];
                }
            }
            curEdgeNum++;
        }
    }
    std::cout << "Kruskal Spanning Tree total cost: " << totalCost << std::endl;
}