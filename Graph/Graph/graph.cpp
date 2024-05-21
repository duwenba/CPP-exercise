//
// Created by 22753 on 2024/5/21.
//

#include <iostream>
#include "graph.h"
#include <set>
#include <iomanip>
#include <random>

Graph::Graph(const Matrix& mat) {
    fromMatrix((int)mat.size(), mat);
}


void Graph::fromMatrix(int n, const vector<vector<int>> &mat) {

    matrix = mat;

    nodeNum = n;
//    nodeArr.resize(n);
    arcArr.resize(n);
    for (int i = 0; i < n; i++) {
//        nodeArr[i].value = i;
        arcArr[i].value = i;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0 && !isinf(mat[i][j])) {
                // 局部变量node
                auto node = new Node{
                        .value = j,
                        .weight = mat[i][j],
                        .next = arcArr[i].next
                };
                arcArr[i].next = node;
            }
        }
    }
}

int Graph::getNodeNum() const {
    return nodeNum;
}

void Graph::dfs(int start, vector<bool> &visited) const {
    visited[start] = true;
    cout << start << " ";
    Node *p = arcArr[start].next;
    while (p) {
        if (!visited.at(p->value)) {
            dfs(p->value, visited);
        }
        p = p->next;
    }
}

void Graph::bfs(int start) const {
    queue<int> q;
    vector<bool> visited(nodeNum, false);
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        Node *p = arcArr[u].next;
        while (p) {
            if (!visited.at(p->value)) {
                q.push(p->value);
                visited[p->value] = true;
            }
            p = p->next;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < nodeNum; i++) {
        Node *p = arcArr[i].next;
        while (p) {
            Node *q = p->next;
            delete p;
            p = q;
        }
        arcArr[i].next = nullptr;
    }
}

const Matrix &Graph::getMatrix() {
    return matrix;
}


auto Graph::PrintMatrix() -> void {
    for (const auto& row: matrix) {
        std::cout << "|";
        for (auto & elem: row) {
            if (elem == INF)
                std::cout << " - |";
            else
                std::cout << std::setw(3) << std::setfill(' ') << elem << "|";
        }
        std::cout << std::endl;
    }
}



