#include <iostream>
//#include <queue>
//#include "Queue.hpp"
#include "LinkQueue.hpp"

int a[] = {1,2,3,4,5,6,7,8};
LinkQueue<int> mQueue;

int main() {
//    mQueue.asHead();
    for(int i = 1; i <= 15;i++){
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
    return 0;
}
