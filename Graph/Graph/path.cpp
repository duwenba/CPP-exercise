//
// Created by 22753 on 2024/5/21.
//

#include <random>
#include <iomanip>
#include "graph.h"
#include <Graph/graph.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

auto PrintPath(const vector<int> &prev, int end) -> void {
    if (prev[end] == -1) {
        cout << end << " ";
        return;
    }
    PrintPath(prev, prev[end]);
    cout << end << " ";
}

auto Graph::Dijkstra(int start) -> void {
    auto &mat = matrix;
    // variables initialization
    int n = mat.size();  // number of vertices
    vector<int> distFromStart(n, INF);  // shortest distance from start
    vector<int> prev(n, -1);  // previous vertex in the shortest path
    // the set of vertices having the shortest distance from start
    set<int> visited, unvisited;
    visited.insert(start);
    distFromStart[start] = 0;
    for (int i = 0; i < n; i++) unvisited.insert(i);
    unvisited.erase(start);

    for (int i = 1; i < n; i++) {
        distFromStart[i] = mat[start][i];  // initialize the distance from start to i
        if (mat[start][i] < INF) {
            prev[i] = start;          // initialize the previous vertex in the shortest path
        }
    }

    // Dijkstra algorithm
    while (!unvisited.empty()) {
        int minDist = INF;
        int minIndex = -1;
        // find the vertex with the minimum distance from start
        for (auto &u: unvisited) {
            if (distFromStart[u] < minDist) {
                minDist = distFromStart[u];
                minIndex = u;
            }
        }
        if (minIndex == -1) break; // no more unvisited vertices
        // insert the vertex with the minimum distance from start into the visited set
        visited.insert(minIndex);
        unvisited.erase(minIndex);
        // update the distance and previous vertex of the adjacent vertices
        for (auto &u: unvisited) {
            if (mat[minIndex][u] != INF) {
                int newDist = distFromStart[minIndex] + mat[minIndex][u];
                if (newDist < distFromStart[u]) {
                    distFromStart[u] = newDist;
                    prev[u] = minIndex;
                }
            }
        }
    }

    // print the shortest path from start to all vertices
    for (int i = 0; i < n; i++) {
        if (distFromStart[i] != INF) {
            cout << "The shortest path from " << start << " to " << i << " is: ";
            PrintPath(prev, i);
            cout << endl;
            cout << "The distance is: " << distFromStart[i] << endl << endl;
        }
    }
}

bool Graph::hasPath(int start, int end, vector<bool> &visited) const {
    if (start == end) {
        return true;
    }
    visited[start] = true;
    Node *p = arcArr[start].next;
    while (p) {
        if (!visited.at(p->value) && hasPath(p->value, end, visited))
            // && �Ǽ������, p δ�����ʹ��Ż�����ݹ�����
        {
            return true; // �ҵ�·�� ֱ�ӷ��� true
        }
        p = p->next;  // δ�ҵ�·��, ����������һ���ڵ�
    }
    return false; // δ�ҵ�·��, ���� false
}

vector<vector<int>> Graph::findAllPaths(int start, int end, vector<bool> &visited) const {
    vector<vector<int>> paths;
    if (start == end) { // �ݹ���ֹ����: �����յ���ͬ,���ҵ�һ��·��, ֱ�ӷ��ص�ǰ�ڵ�
        paths.push_back({start});
        return paths;
    }

    // �ݹ�����
    visited[start] = true;
    Node *p = arcArr[start].next;

    while (p) {
        if (!visited.at(p->value)) {
            // �ݹ������ӽڵ�
            auto subPaths = findAllPaths(p->value, end, visited);
            for (auto subPath: subPaths) {
                subPath.insert(subPath.begin(), start); // �������
                paths.push_back(subPath);
            }
        }
        p = p->next;
    }

    // ����
    visited[start] = false; // ����, ��ǽڵ�δ������ , ���ڼ�������

    return paths;
}

auto Graph::Floyd() -> void {

    // ������ʼ��
    auto &mat = matrix; // �ڽӾ���
    int n = (int) mat.size();    // ������
    auto distance = mat;  // ��̾������
    Matrix path(n, vector<int>(n, INF)); // ��¼·�� INF ��ʾ����ת


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] != INF && distance[k][j] != INF // ���Դ� i �� k �ٵ� j
                    and distance[i][k] + distance[k][j] < distance[i][j]) // ��ת�������
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = k; // ��¼·��
                }
            }

        }
    }

    // ������
    cout << "The shortest distance matrix is: " << endl;
    PrintMatrix(distance);
    cout << endl;

    cout << "The path matrix is: " << endl;
    PrintMatrix(path);
    cout << endl;

}