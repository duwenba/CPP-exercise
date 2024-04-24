#pragma once

#include <cstring>
#include <iostream>
#include <memory>
#include <stack>
#include <queue>
#include <string>

using std::shared_ptr;
using std::queue;
using std::stack;
using std::string;

template<typename T = char>
class BTree {
public:
    BTree() = default;

    /** Constructor with string input like "A(B(C,D),E)"
     * @param str :�ַ�������
     * @note
     * �ַ�����������������ƥ��ĸ�ʽ--"ֵ(������,������))"������Ƕ�׶������,����"A(B(C,D),E)"
     */
    explicit BTree(const char *str);

    explicit BTree(const T &value)
            : value(value), left(nullptr), right(nullptr) {};

    ~BTree() = default;

    void display();

    /** ǰ�����
    * @param visit : ���ʺ���
    * @note ���ʺ����Ķ���Ϊvoid visit(T& value)�������Ϊ��ǰ�ڵ��ֵ�����Զ�����в���
    */
    void preorder(void (*visit)(T &));

    /// �������
    /// @param visit : ���ʺ���
    ///@note ���ʺ����Ķ���Ϊvoid visit(T&
    /// value)�������Ϊ��ǰ�ڵ��ֵ�����Զ�����в���
    void inorder(void (*visit)(T &));

    /// �������
    /// @param visit : ���ʺ���
    ///@note ���ʺ����Ķ���Ϊvoid visit(T&
    /// value)�������Ϊ��ǰ�ڵ��ֵ�����Զ�����в���
    void postorder(void (*visit)(T &));

    /// �������
    /// @param visit : ���ʺ���
    ///@note ���ʺ����Ķ���Ϊvoid visit(T& value)�������Ϊ��ǰ�ڵ��ֵ�����Զ�����в���
    void levelorder(void (*visit)(T &));

    // �����ĸ߶�
    int height();

    // ��Ҷ�ӽڵ������
    int countLeaves();

private:
    T value;
    shared_ptr<BTree<T>> left;
    shared_ptr<BTree<T>> right;
};

template<typename T>
void BTree<T>::display() {
    std::cout << value;
    if (left == nullptr && right == nullptr)
        return;
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
    BTree<T> *curr = nullptr;
    stack<BTree<T> *> stk;
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
                // set the flag to 0 to indicate that the next character is the right
                // child of the current node
                flag = 2;
                break;
            default:
                // add the character to the current node
                if (curr == nullptr) {
                    curr = this;
                    this->value = str[i];
                } else
                    curr = new BTree<T>(str[i]);
                // set the left or right child of the current node based on the flag
                if (flag == 1) {
                    stk.top()->left = shared_ptr<BTree<T>>(curr);
                } else if (flag == 2) {
                    stk.top()->right = shared_ptr<BTree<T>>(curr);
                }
                break;
        }
    }
}

// ǰ�����
template<typename T>
void BTree<T>::preorder(void (*visit)(T &)) {
    if (this->value != '\0') {
        visit(this->value);
    }
    if (this->left) {
        this->left->preorder(visit);
    }
    if (this->right) {
        this->right->preorder(visit);
    }
}

// �������
template<typename T>
void BTree<T>::inorder(void (*visit)(T &)) {
    if (this->left) {
        this->left->inorder(visit);
    }
    if (this->value != '\0') {
        visit(this->value);
    }
    if (this->right) {
        this->right->inorder(visit);
    }
}

// �������
template<typename T>
void BTree<T>::postorder(void (*visit)(T &)) {
    if (this->left) {
        this->left->postorder(visit);
    }
    if (this->right) {
        this->right->postorder(visit);
    }
    if (this->value != '\0') {
        visit(this->value);
    }
}

// �������
template<typename T>
void BTree<T>::levelorder(void (*visit)(T &)) {
    queue<BTree<T> *> q;
    q.push(this);
    while (!q.empty()) {
        BTree<T> *node = q.front();
        q.pop();
        if (node->value != '\0') {
            visit(node->value);
        }
        if (node->left) {
            q.push(node->left.get());
        }
        if (node->right) {
            q.push(node->right.get());
        }
    }
}

// �����ĸ߶�
template<typename T>
int BTree<T>::height() {
    int leftHeight = 0, rightHeight = 0;
    if (this->left) {
        leftHeight = this->left->height();
    }
    if (this->right) {
        rightHeight = this->right->height();
    }
    return 1 + std::max(leftHeight, rightHeight);
}

// ��Ҷ�ӽڵ������
template<typename T>
int BTree<T>::countLeaves() {
    int count = 0;
    if (this->left == nullptr && this->right == nullptr) {
        count++;
    } else {
        if (this->left) {
            count += this->left->countLeaves();
        }
        if (this->right) {
            count += this->right->countLeaves();
        }
    }
    return count;
}