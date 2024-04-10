//
// Created by 22753 on 2024/4/10.
//

#include <stdio.h>
#include <iostream>
#include <stack>



// 递归方法实现Hanoi问题
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n-1, aux, to, from);
}

// 非递归方法实现Hanoi问题
struct HanoiState {
    int n;
    char from, to, aux;
    int state;  // 0: move n-1 disks from from to aux, 1: move n-1 disks from aux to to, 2: move n-1 disks from from to to
};

void iterativeHanoi(int n, char from, char to, char aux) {
    std::stack<HanoiState> stateStack;
    stateStack.push({n, from, to, aux, 0});

    while (!stateStack.empty()) {
        HanoiState &currentState = stateStack.top();
        switch (currentState.state) {
            case 0:
                if (currentState.n == 1) {
                    std::cout << "Move disk 1 from " << currentState.from << " to " << currentState.to << std::endl;
                    stateStack.pop();
                } else {
                    stateStack.push({currentState.n - 1, currentState.from, currentState.aux, currentState.to, 0});
                    currentState.state = 1;
                }
                break;

            case 1:
                std::cout << "Move disk " << currentState.n << " from " << currentState.from << " to " << currentState.to << std::endl;
                stateStack.top().state = 2;
                stateStack.push({currentState.n - 1, currentState.aux, currentState.to, currentState.from, 0});
                break;

            case 2:
                stateStack.pop();
                break;
        }
    }
}

// 主函数
int main() {
    int n = 3;
    std::cout << "Recursive Hanoi:" << std::endl;
    hanoi(n, 'A', 'C', 'B');
    std::cout << "Iterative Hanoi:" << std::endl;
    iterativeHanoi(n, 'A', 'C', 'B');
    //pause
    system("pause");
    return 0;
}
