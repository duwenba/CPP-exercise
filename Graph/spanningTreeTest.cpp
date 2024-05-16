//
// Created by 22753 on 2024/5/14.
//
#include "spanningTree.h"
#include <limits>
#include <iostream>



// 邻接矩阵
Matrix mat = {
        {0,   28,  INF, INF, INF, 10,  INF},
        {28,  0,   16,  INF, INF, INF, 14},
        {INF, 16,  0,   12,  INF, INF, INF},
        {INF, INF, 12,  0,   22,  INF, 18},
        {INF, INF, INF, 22,  0,   25,  24},
        {10,  INF, INF, INF, 25,  0,   INF},
        {INF, 14,  INF, 18,  24,  INF, 0},
};


int main() {
    // 深度优先生成树
    auto dfsTree = dfsSpanningTree(mat);
    // 打印生成树
    std::cout << "DFS Spanning Tree:" << std::endl;
    for (auto &tree : dfsTree) {
        printTree(tree);
    }
    std::cout << "\n";

    // 宽度优先生成树
    auto bfsTree = bfsSpanningTree(mat);
    // 打印生成树
    std::cout << "BFS Spanning Tree:" << std::endl;
    for (auto &tree : bfsTree) {
        printTree(tree);
    }
    std::cout << "\n";

    // PRIM 算法生成最小生成树
    std::cout << "PRIM Spanning Tree:" << std::endl;
    primSpanningTree(mat, 0);
    std::cout << "\n";

    // Kruskal 算法生成最小生成树
    std::cout << "Kruskal Spanning Tree:" << std::endl;
    kruskalSpanningTree(mat);
    std::cout << "\n";

    return 0;
}