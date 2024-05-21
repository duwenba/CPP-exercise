// creat by duwenba 2024/5/8

#pragma once


#include <vector>
#include <limits>
#include <cmath>
#include <queue>

using Matrix = std::vector<std::vector<int>>;
const int INF = std::numeric_limits<int>::max();

using namespace std;
// 邻接矩阵表示法

// 节点
class Node {
public:
    int value{0}; // 节点值
    int weight{0}; // 权重
    Node *next = nullptr;// 指向下一个节点
};

// 边节点
class ArcNode {
public:
    int value{0};
//    int weight{0};
    Node *next = nullptr;
};

// 领接表表示法
class Graph {
private:
//    vector<Node> nodeArr;
    vector<ArcNode> arcArr;
    int nodeNum{0};

    Matrix matrix; // 邻接矩阵

public:
     int getNodeNum() const;

public:
    Graph() = default;
    explicit Graph(const Matrix& mat) ;
    ~Graph();

    // 从邻接矩阵构造图
    void fromMatrix(int n, const vector<vector<int>> &mat);

    // DFS遍历
    void dfs(int start, vector<bool> &visited) const;
    // BFS遍历
    void bfs(int start) const;

    // 判断两个节点之间是否有简单路径
    bool hasPath(int start, int end, vector<bool> &visited) const;
    // 找到两节点间所有简单路径
    auto findAllPaths(int start, int end, vector<bool> &visited) const -> vector<vector<int>>;

    /// Dijijkstra algorithm
    /// \param mat The adjacency matrix of the graph
    /// \param start The start vertex
    /// \return Print the shortest path from start to all vertices
    auto Dijkstra(int start) -> void;

    const Matrix &getMatrix();

    auto PrintMatrix() -> void ;

public:
    static const int MaxValue = 100; // the maximum value of each edge

    /// generate a Undricted graph
    /// \param n the number of vertices in the graph
    /// \param seed the seed of random number generator.
    ///  \note if seed is not given, use a fixed seed, that will generate the same graph every time.
    /// \return a Matrix of a undirected graph
    static auto generateUndrict(int n, unsigned int = 0) -> Graph;

    /// generate a  directed graph
    /// \param n the number of vertices in the graph
    /// \param seed the seed of random number generator.
    ///  \note if seed is not given, use a fixed seed, that will generate the same graph every time.
    /// \return a Matrix of a directed graph
    static auto generateDirected(int n, unsigned int = 0) -> Graph;
};


