#include <cstdio>
#include "Linked_Stack.hpp"
//#include "Stack.hpp"
//#include <algorithm>
//#include <stack>
//using namespace std;
int a[] = {1,2,3,4,5};

int main(){
    Stack<int> mStack = Stack<int>(a,5);
    mStack.push(6);
    mStack.push(7);
    while (!mStack.empty()){
        printf("%d ", mStack.top());
        mStack.pop();
    }
}