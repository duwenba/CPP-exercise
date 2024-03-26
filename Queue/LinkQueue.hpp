//
// Created by 22753 on 2024/3/25.
//

//#pragma once
#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H

template<typename T>
class LinkQueue {
private:
    T data;
    LinkQueue<T> *next;
    LinkQueue<T> *front_pr,*rear_pr;
public:
    LinkQueue():front_pr(this),rear_pr(this), next(nullptr) {};
    LinkQueue(T x):data(x),next(nullptr) {};
//    void asHead();
    void push(T x);
    T pop();
    bool empty();
    T front();
    T rear();
//    int length();
};

template<typename T>
T LinkQueue<T>::rear() {
    return rear_pr->data;
}

template<typename T>
T LinkQueue<T>::front() {
    return front_pr->next->data;
}

//template<typename T>
//void LinkQueue<T>::asHead() {
//    front_pr = this;
//    rear_pr = this;
//}

template<typename T>
T LinkQueue<T>::pop() {
    if(empty()) { throw "queue is empty!!"; }
    auto temp = front_pr->next;
    front_pr->next = temp->next;
    return temp->data;
}

template<typename T>
bool LinkQueue<T>::empty() {
    return front_pr->next == nullptr;
}

template<typename T>
void LinkQueue<T>::push(T x) {
    rear_pr->next = new LinkQueue<T>(x);
    rear_pr = rear_pr->next;
}

#endif //QUEUE_CIRCLEQUEUE_H