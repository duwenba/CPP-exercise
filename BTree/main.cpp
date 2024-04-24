#include "BTree.hpp"

//��������
int main() {
  BTree<char> bt("A(B(C,D),E)");
  bt.display();
  std::cout << std::endl;
  
  //����Ҫ��ÿһ���ڵ���еĲ��� ---- ��ӡ�ڵ�ֵ
  auto printChar = [](char & c) { std::cout << c << " "; };

  //���Ա���
  std::cout << "���������";
  bt.preorder(printChar);
  std::cout << std::endl;
  std::cout << "���������";
  bt.inorder(printChar);
  std::cout << std::endl;
  std::cout << "���������";
  bt.postorder(printChar);
  std::cout << std::endl;
  std::cout << "���������";
  bt.levelorder(printChar);
  std::cout << std::endl;

  std::cout << "���ĸ߶�Ϊ��"     << bt.height()  << std::endl
            << "����Ҷ�ӽڵ���Ϊ��"<< bt.countLeaves();
  return 0;
}