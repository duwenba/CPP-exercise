//
// Created by 22753 on 2024/3/25.
//
#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H

//stack<int>
#include <stdexcept>



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
    T *pop();
    T* top();
    void  push(T x);
    bool empty();
    void reverse();
};

template<typename T>
void Stack<T>::reverse() {
    if(empty()) { throw std::runtime_error("Stack is empty !!"); }
    Stack<T> p;
    while (!empty()) {
       p.push(*pop());
    }
    this->next = p.next;
}

template<typename T>
void Stack<T>::push(T x) {
    auto* tmep = new Stack<T>(x);
    tmep->next = this->next;
    this->next = tmep;
}

template<typename T>
T* Stack<T>::top() {
    if(empty()) { throw std::runtime_error("Stack is empty !!"); }
    return &(this->next->data);
}

template<typename T>
bool Stack<T>::empty() {
    return this->next == nullptr;
}

template<typename T>
T* Stack<T>::pop() {
    if(empty()) { throw std::runtime_error("Stack is empty !!"); }
    Stack<T> *top = this->next;
    this->next = top->next;
    T result = top->data;
    return &(top->data);
}

template<typename T>
Stack<T>::Stack(T *a, int n) {
    for (int i = 0; i < n; i++) {
        push(a[i]);
    }
}

#endif //LINKSTACK_H