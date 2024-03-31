//
// Created by 22753 on 2024/3/25.
//
#pragma once
#ifndef STACK_H
#define STACK_H
//#include <exception>

#include <stdexcept>

///default size is 20.
template<typename Type,int size=40>
class Stack {
private:
    Type data[size];
    int top_pr = -1;
public:
    Stack()= default;
    Stack(Type a[],int n);
    bool empty();
    void push(Type x);
    Type* pop();
    Type* top();
};

template<typename Type, int size>
Type* Stack<Type, size>::top() {
    return &(data[top_pr]);
}

template<typename Type, int size>
bool Stack<Type, size>::empty() {
    return top_pr == -1;
}

template<typename Type, int size>
Type* Stack<Type, size>::pop() {
    if( empty() ) { throw  std::runtime_error("Stack is Empty !!"); }
    return &(data[top_pr--]);
}

template<typename Type, int size>
void Stack<Type, size>::push(Type x) {
    if (top_pr + 1 >= size) {throw std::runtime_error ("Stack is full!!");}
    data[++top_pr] = x;
}

template<typename Type, int size>
Stack<Type, size>::Stack(Type *a, int n) {
    if (n > size) { throw std::runtime_error("your input is out of size !!"); }
    for(int i = 0;i < n;i++){
        data[i] = a[i];
        top_pr++;
    }
}


#endif //LIST_STACK_H
