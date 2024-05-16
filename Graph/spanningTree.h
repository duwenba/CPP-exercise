#pragma once

#include <vector>
#include <limits>
//#include <utils/tree_node.hpp>

using Matrix = std::vector<std::vector<int>>;
const int INF = std::numeric_limits<int>::max();

struct TreeNode {
    int val;
    std::vector<TreeNode *> children;

    explicit TreeNode(int val) : val(val) {};

    ~TreeNode() {
        for (auto child: children) {
            delete child;
        }
    }
};

struct Edge {
    int u, v, w;
};
/// 打印树的结构
///@param root  根节点
///@param first  是否是第一个节点(辅助参数, 默认为true, 无需传入)
void printTree(TreeNode *root, bool first = true);

/// 深度优先遍历得到生成树
///@param graph  邻接矩阵
///@return  生成树的列表(如果是非连通图,有多个生成树)
std::vector<TreeNode *> dfsSpanningTree(const Matrix &graph);

/// 广度优先遍历得到生成树
///@param graph  邻接矩阵
///@return  生成树的列表(如果是非连通图,有多个生成树)
auto bfsSpanningTree(const Matrix &graph) -> std::vector<TreeNode *>;

// Prim算法得到生成树
void primSpanningTree(const Matrix &graph, int start);

// Kruskal算法得到最小生成树
auto kruskalSpanningTree(const Matrix &graph) -> void;