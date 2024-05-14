#pragma once

#include <vector>
#include <limits>
//#include <utils/tree_node.hpp>

using Matrix = std::vector<std::vector<int>>;
const int INF = std::numeric_limits<int>::max();

struct TreeNode {
    int val;
    std::vector<TreeNode*> children;
    explicit TreeNode(int val) : val(val) {};
    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

void printTree(TreeNode* root);

/// 深度优先遍历得到生成树
///@param graph  邻接矩阵
///@return  生成树的列表(如果是非连通图,有多个生成树)
std::vector<TreeNode *> dfsSpanningTree(const Matrix& graph);

// 广度优先遍历得到生成树
std::vector<TreeNode *> bfsSpanningTree(const Matrix& graph) ;

// Prim算法得到生成树
void primSpanningTree(const Matrix& graph, std::vector<int>& parent, int start) ;

// Kruskal算法得到最小生成树
void kruskalSpanningTree(const Matrix& graph, std::vector<int>& parent, std::vector<int>& rank, std::vector<int>& edge) ;