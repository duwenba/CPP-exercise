#include <iostream>
//#include <queue>
//#include "Queue.hpp"
#include "LinkQueue.hpp"
//#include "CircleQueue.h"

#ifdef _GLIBCXX_QUEUE
std::queue<int> mQueue;
#endif
#ifdef QUEUE_LINKQUEUE_H
LinkQueue<int> mQueue;
#endif
#ifdef QUEUE_CIRCLEQUEUE_H
CircleQueue<int> mQueue;
#endif
#ifdef QUEUE_QUEUE_H
Queue<int> mQueue;
#endif


int main() {

//    LinkQueue<int> mQueue;

    for(int i = 1; i <= 8;i++){
        mQueue.push(i);
    }
    int n = 1;
    while (!mQueue.empty()){
        if ((n)%2 == 0) {
            mQueue.push(mQueue.front());
            mQueue.pop();
        }
        else {
            std::cout << mQueue.front() << ' ' ;
            mQueue.pop();
        }
        n++;
    }
    for(int i = 1; i <= 8;i++){
        mQueue.push(i);
    }
    return 0;
}
