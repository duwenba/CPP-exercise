#include "BTree.hpp"


//test the BTree class
int main() {
    BTree<> tree("A(B(C,D),E(F,G)");
    tree.display();
    return 0;
}

/** 用字符表示树的结构：
 *
 *
 *      ┏ C
 *  ┏ B ┫
 *  ┫   ┗ D
 *A ┫
 *  ┫   ┏ F
 *  ┗ E ┫
 *      ┗ G
 */
/*
