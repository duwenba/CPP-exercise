// creat by duwenba 2024/5/8

#include <vector>
#include <limits>
#include <cmath>
#include <queue>

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
public:
    [[nodiscard]] int getNodeNum() const;

public:
    Graph() = default;
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
    vector<vector<int>> findAllPaths(int start, int end, vector<bool> &visited) const;

    /* Dijsktra算法的计算步骤
     *
     * 1. 初始化一个数组 dist, dist[i] 表示从起点到 i 的最短距离, 初始值都设置为无穷大
     * 2. 将起点 dist[start] 设置为 0, 并将其标记为已访问
     * 3. 循环遍历未访问的节点, 对每个节点 i:
     *    a. 计算 i 到起点的距离 dist[i] = dist[start] + 权重(start, i)
     *    b. 若 dist[i] < dist[j], 则更新 dist[j] = dist[i]
     *    c. 将 i 标记为已访问
     * 4. 返回 dist 数组, 其中 dist[i] 表示从起点到 i 的最短距离
     *
     */
    vector<int> dijkstra(int start,vector<bool> &visited) const;

};

void Graph::fromMatrix(int n, const vector<vector<int>> &mat) {
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

bool Graph::hasPath(int start, int end, vector<bool> &visited) const {
    if (start == end) {
        return true;
    }
    visited[start] = true;
    Node *p = arcArr[start].next;
    while (p) {
        if (!visited.at(p->value) && hasPath(p->value, end, visited))
        // && 非简洁运算, p 未被访问过才会继续递归搜索
        {
            return true; // 找到路径 直接返回 true
        }
        p = p->next;  // 未找到路径, 继续搜索下一个节点
    }
    return false; // 未找到路径, 返回 false
}

vector<vector<int>> Graph::findAllPaths(int start, int end, vector<bool> &visited) const {
    vector<vector<int>> paths;
    if (start == end) { // 递归终止条件: 起点和终点相同,即找到一条路径, 直接返回当前节点
        paths.push_back({start});
        return paths;
    }

    // 递归搜索
    visited[start] = true;
    Node *p = arcArr[start].next;

    while (p) {
        if (!visited.at(p->value)) {
            // 递归搜索子节点
            auto subPaths = findAllPaths(p->value, end, visited);
            for (auto subPath: subPaths) {
                subPath.insert(subPath.begin(), start); // 插入起点
                paths.push_back(subPath);
            }
        }
        p = p->next;
    }

    // 回溯
    visited[start] = false; // 回溯, 标记节点未被访问 , 便于继续搜索

    return paths;
}

vector<int> Graph::dijkstra(int start, vector<bool> &visited) const {
    vector<int> dist(nodeNum, numeric_limits<int>::max()); // 记录从起点到各节点的最短距离
    dist[start] = 0; // 起点到起点的距离为0
    priority_queue<pair<int, int>> pq; // 优先队列, 元素为(距离, 节点)
    pq.emplace(0, start); // 起点入队
    while (!pq.empty()) {
        int d = -pq.top().first; // 距离
        int u = pq.top().second; // 节点
        pq.pop();
        if (visited[u]) { // 节点已访问, 跳过
            continue;
        }
        visited[u] = true; // 标记节点已访问
        Node *p = arcArr[u].next;
        while (p) {
            int v = p->value;
            int w = p->weight;
            if (dist[u] + w < dist[v]) { // 更新距离
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v); // 入队
            }
            p = p->next;
            // 若有负权回路, 则 dist[v] 可能更新为负数, 但此时并不影响结果, 因为负权回路的存在不会影响最终结果
        }

    }
    return dist;
}

