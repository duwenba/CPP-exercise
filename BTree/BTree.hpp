#pragma once

#include <string>
#include <cstring>
#include <stack>
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::stack;
using std::string;

template<typename T = char>
class BTree {
public:
    BTree() = default;

    /** Constructor with string input like "A(B(C,D),E)"
     * @param str :字符串输入
     * @note 字符串输入必须符合括号匹配的格式--"值(左子树,右子树))"，可以嵌套多层括号,比如"A(B(C,D),E)"
     */
    explicit BTree(const char *str);

    explicit BTree(const T& value) : value(value), left(nullptr), right(nullptr) {};

    ~BTree() = default;

    void display();

private:

    T value;
    shared_ptr<BTree<T> > left;
    shared_ptr<BTree<T> > right;

};

template<typename T>
void BTree<T>::display() {
    std::cout << value;
    if (left == nullptr && right == nullptr) return;
    std::cout << "(";
    if (left) {
        left->display();
    }
    std::cout << ",";
    if (right) {
        right->display();
    }
    std::cout << ")";
}

template<typename T>
BTree<T>::BTree(const char *str) {
    int flag = 0;
    BTree<T> * curr = nullptr;
    stack<BTree<T>*> stk;
    for (int i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case '(':
                // push the current node to the stack
                stk.push(curr);
                flag = 1;
                break;
            case ')':
                // pop the top node from the stack and set it as the current node
                stk.pop();
                break;
            case ',':
                // set the flag to 0 to indicate that the next character is the right child of the current node
                flag = 2;
                break;
            default:
                // add the character to the current node
                if (curr == nullptr) {
                    curr = this;
                    this->value = str[i];
                }
                else curr = new BTree<T>(str[i]);
                // set the left or right child of the current node based on the flag
                if (flag == 1) {
                    stk.top()->left = shared_ptr<BTree<T> >(curr);
                } else if (flag == 2) {
                    stk.top()->right = shared_ptr<BTree<T> >(curr);
                }
                break;
        }
    }
}
