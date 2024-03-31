//
// Created by 22753 on 2024/3/25.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template<typename T,int size = 20>
class Queue {
private:
    T data[size];
    int front_pr,rear_pr;
    //头部不存储数据
public:
    Queue(): front_pr(0), rear_pr(0) {};
    void push(T x);
    T pop();
    bool empty();
    int length();
    T front();
    T rear();
};

template<typename T, int size>
T Queue<T, size>::rear() {
    return data[rear_pr];
}

template<typename T, int size>
T Queue<T, size>::front() {
    return data[front_pr+1];
}

template<typename T, int size>
int Queue<T, size>::length() {
    return rear_pr - front_pr;
}

template<typename T, int size>
bool Queue<T, size>::empty() {
    return front_pr == rear_pr;
}

template<typename T, int size>
T Queue<T, size>::pop() {
    return data[1 + front_pr++];
}


template<typename T, int size>
void Queue<T, size>::push(T x) {
    data[++rear_pr] = x;
}

#endif //QUEUE_QUEUE_H