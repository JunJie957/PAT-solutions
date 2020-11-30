#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int v;  // ��һ��Ŀ��ڵ�
    int w;  // ����Ŀ��ڵ�ı�Ȩֵ
    node(int a, int b) :v(a), w(b) {}
};

const int maxn = 510;
const int INF = 1000000000;

int n, m, c1, c2, num, r1, r2, val;
vector<int> weights;    // ��Ȩ - ��������
vector<node> adj[maxn]; // �ڽӱ�
vector<int> path;       // ���·��������
vector<int> hands;      // ·����̵���������ֵ�����
vector<int> dis;        // ��㵽�ﵱǰ�ڵ�ľ���
bool vis[maxn] = { false }; // �Ƿ���ʹ�

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
                    path[v] += path[u]; // ���·������
                    if (hands[u] + weights[v] > hands[v]) {
                        hands[v] = hands[u] + weights[v]; // ���Ķ�������
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
