#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int v;  // 另一个目标节点
    int w;  // 到达目标节点的边权值
    node(int a, int b) :v(a), w(b) {}
};

const int maxn = 510;
const int INF = 1000000000;

int n, m, c1, c2, num, r1, r2, val;
vector<int> weights;    // 点权 - 队伍数量
vector<node> adj[maxn]; // 邻接表
vector<int> path;       // 最短路径的数量
vector<int> hands;      // 路径最短的情况，帮手的数量
vector<int> dis;        // 起点到达当前节点的距离
bool vis[maxn] = { false }; // 是否访问过

void Dijkstra(int s) {
    dis.resize(n), path.resize(n), hands.resize(n);
    fill(dis.begin(), dis.end(), INF);
    fill(path.begin(), path.end(), 0);
    fill(hands.begin(), hands.end(), 0);
    dis[s] = 0;
    path[s] = 1;
    hands[s] = weights[s];
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].v;
            if (vis[v] == false) {
                if (dis[u] + adj[u][j].w < dis[v]) {
                    dis[v] = dis[u] + adj[u][j].w;
                    hands[v] = hands[u] + weights[v];
                    path[v] = path[u];
                } else if (dis[u] + adj[u][j].w == dis[v]) {
                    path[v] += path[u]; // 最短路径条数
                    if (hands[u] + weights[v] > hands[v]) {
                        hands[v] = hands[u] + weights[v]; // 最大的队伍数量
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        weights.emplace_back(num);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &r1, &r2, &val);
        adj[r1].emplace_back(node(r2, val));
        adj[r2].emplace_back(node(r1, val));
    }
    Dijkstra(c1);
    printf("%d %d", path[c2], hands[c2]);
    return 0;
}
