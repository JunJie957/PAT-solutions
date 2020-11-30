#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 501;
const int INF = 1000000000;

struct node {
    int v;    // 到达另一个节点
    int w;    // 距离
    int cost; // 花费
    node(int a, int b, int c) :v(a), w(b), cost(c) {};
};

int n, m, s, d, r1, r2, w, cost;
vector<int> pre;
vector<int> dis;
vector<int> costs;
vector<node> adj[maxn];
bool vis[maxn] = { false };

void Dijkstra(int s) {
    dis.resize(n), costs.resize(n), pre.resize(n);
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
    }
    fill(dis.begin(), dis.end(), INF);
    fill(costs.begin(), costs.end(), 0);
    dis[s] = 0;
    costs[s] = 0;
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
        for (int k = 0; k < adj[u].size(); ++k) {
            int v = adj[u][k].v;
            if (vis[v] == false) {
                if (dis[u] + adj[u][k].w < dis[v]) { // 保证路径最短
                    dis[v] = dis[u] + adj[u][k].w;
                    costs[v] = costs[u] + adj[u][k].cost;
                    pre[v] = u;
                } else if (dis[u] + adj[u][k].w == dis[v]) { // 在路径最短的前提下，保证花费最小
                    if (costs[u] + adj[u][k].cost < costs[v]) {
                        costs[v] = costs[u] + adj[u][k].cost;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

// 递归找到最短路径
void DFS(int s, int d) {
    if (s == d) {
        printf("%d ", d);
        return;
    }
    DFS(s, pre[d]);
    printf("%d ", d);
}

/*
     N (≤500) is the number of cities (and hence the cities are numbered from 0 to N?1); 
     M is the number of highways;
     S and D are the starting and the destination cities, 
*/
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &r1, &r2, &w, &cost);
        adj[r1].emplace_back(node(r2, w, cost));
        adj[r2].emplace_back(node(r1, w, cost));
    }
    Dijkstra(s);
    DFS(s, d);
    printf("%d %d", dis[d], costs[d]);
    return 0;
}
