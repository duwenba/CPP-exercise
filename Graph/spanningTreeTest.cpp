//
// Created by 22753 on 2024/5/14.
//
#include "spanningTree.h"
#include <limits>
#include <iostream>



// 邻接矩阵
// 0 1 1 inf inf 1
// 1 0 inf 1 1 inf
// 1 inf 0 inf inf inf
// inf 1 inf 0 1 inf
// inf 1 inf 1 0 inf
// 1 inf inf inf inf 0

Matrix mat = {
        {0,   1,   1,   INF, INF, 1},
        {1,   0,   INF, 1,   1,   INF},
        {1,   INF, 0,   INF, INF, INF},
        {INF, 1,   INF, 0,   1,   INF},
        {INF, 1,   INF, 1,   0,   INF},
        {1,   INF, INF, INF, INF, 0}
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

    return 0;
}