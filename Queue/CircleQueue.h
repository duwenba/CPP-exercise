//
// Created by 22753 on 2024/3/26.
//

#ifndef QUEUE_CIRCLEQUEUE_H
#define QUEUE_CIRCLEQUEUE_H

template<typename T,int size = 20>
class CircleQueue {
private:
    T data[size];
    int front_pr,rear_pr;
    //头部不存储数据
public:
    CircleQueue(): front_pr(0), rear_pr(0) {};
    void push(T x);
    T pop();
    bool empty();
    int length();
    T front();
    T rear();
};

template<typename T, int size>
T CircleQueue<T, size>::rear() {
    return data[rear_pr];
}

template<typename T, int size>
T CircleQueue<T, size>::front() {
    return data[front_pr+1];
}

template<typename T, int size>
[[maybe_unused]] int CircleQueue<T, size>::length() {
    if (front_pr == rear_pr) {
        return 0;
    } else {
        return (rear_pr - front_pr + size) % size;
    }
}

template<typename T, int size>
bool CircleQueue<T, size>::empty() {
    return front_pr == rear_pr;
}

template<typename T, int size>
T CircleQueue<T, size>::pop() {
    front_pr = (front_pr + 1) % size;
    return data[front_pr];
}

template<typename T, int size>
void CircleQueue<T, size>::push(T x) {
    rear_pr = (rear_pr + 1) % size;
    data[rear_pr] = x;
}


#endif //QUEUE_CIRCLEQUEUE_H
