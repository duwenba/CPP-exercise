#include "BTree.hpp"

//测试用例
int main() {
  BTree<char> bt("A(B(C,D),E)");
  bt.display();
  std::cout << std::endl;
  
  //定义要对每一个节点进行的操作 ---- 打印节点值
  auto printChar = [](char & c) { std::cout << c << " "; };

  //测试遍历
  std::cout << "先序遍历：";
  bt.preorder(printChar);
  std::cout << std::endl;
  std::cout << "中序遍历：";
  bt.inorder(printChar);
  std::cout << std::endl;
  std::cout << "后序遍历：";
  bt.postorder(printChar);
  std::cout << std::endl;
  std::cout << "层序遍历：";
  bt.levelorder(printChar);
  std::cout << std::endl;

  std::cout << "树的高度为："     << bt.height()  << std::endl
            << "树的叶子节点数为："<< bt.countLeaves();
  return 0;
}