#include <cstdio>
#include "Linked_Stack.hpp"
//#include "Stack.hpp"

//#include <stack>
//#include <cstdlib>
//#include <unistd.h>

using namespace std;

int Direction[][2] = {
        {1,0},
        {0,1},
        {0,-1},
        {-1,0},
};

// һ��9*9�����飬��ΧһȦ��1��������0
int a[9][9] = {
        {1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,1},
        {1,1,1,0,0,1,0,0,1},
        {1,0,0,0,1,0,0,1,1},
        {1,0,0,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1}
};


void display();

typedef struct BoxType{
    int x;
    int y;
    int direction;
}Box;

/*
#ifdef _GLIBCXX_STACK
stack<int> mStack = stack<int>();
#endif
#ifdef STACK_H
Stack<int> mStack = Stack<int>();
#endif
#ifdef LINKSTACK_H
LinkStack<int> mStack = LinkStack<int>();
#endif
*/


int main(){
    // �������������1��1������7��7����·��������1��ʾǽ��0��ʾ��
    //1. ����һ��ջ�������洢·��
    Stack<Box> mStack;
    Box start = {1,1,-1};
    mStack.push(start);
    a[1][1] = -1;
    int x,y;

    while(!mStack.empty()){
        auto box = mStack.top();

        if(box->x == 7 && box->y == 7){
            break;
        }
        (box->direction)++;
        for(int * i = &(box->direction); *i < 4; (*i)++){
            x = box->x + Direction[*i][0];
            y = box->y + Direction[*i][1];
            if(a[y][x]==0){
                Box next = {x,y,-1};
                mStack.push(next);
                a[y][x] = -1;
                break;
            }
        }
        if(box->direction >= 4){
            mStack.pop();
            a[box->y][box->x] = 0;
        }
//        display();
    }
    display();
    //output path
    mStack.reverse();
    while(!mStack.empty()){
        auto box = mStack.top();
        mStack.pop();
        printf("(%d,%d) -> ",box->x,box->y);
    }
    printf("�յ�");


    return 0;
}

void display() {
    for(auto & i : a){
        for(int j : i){
            switch (j) {
                case 0: printf(" "); break;
                case -1: printf("*"); break;
                case 1: printf("#"); break;
                default: printf(" ");
            }
//            printf("%2d ",j);
        }
        printf("\n");
    }
}
