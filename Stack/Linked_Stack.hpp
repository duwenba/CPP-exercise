//
// Created by 22753 on 2024/3/25.
//
#pragma once


//stack<int>


template<typename T>
class Stack {
private:
    T data;
    Stack<T> *next = nullptr;
public:
    Stack() = default;
    ~Stack() = default;
    explicit Stack(T x): data(x){};
    Stack(T a[], int n);
    T pop();
    T top();
    void  push(T x);
    bool empty();
};

template<typename T>
void Stack<T>::push(T x) {
    auto* tmep = new Stack<T>(x);
    tmep->next = this->next;
    this->next = tmep;
}

template<typename T>
T Stack<T>::top() {
    if(empty()) { throw "Stack is empty !!"; }
    return this->next->data;
}

template<typename T>
bool Stack<T>::empty() {
    return this->next == nullptr;
}

template<typename T>
T Stack<T>::pop() {
    if(empty()) { throw "Stack is empty !!"; }
    Stack<T> *top = this->next;
    this->next = top->next;
    T result = top->data;
    return top->data;
}

template<typename T>
Stack<T>::Stack(T *a, int n) {
    for (int i = 0; i < n; i++) {
        push(a[i]);
    }
}
