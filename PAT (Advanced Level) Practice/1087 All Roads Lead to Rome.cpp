#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdlib.h>
#include <memory>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int MAXV = 210;
const int INF = 1000000000;

int n, k, u, v, w;
string c1, c2, start, city;
int weight[MAXV];  // 点权
int wt[MAXV];
int pre[MAXV];     // 前驱
int pt[MAXV];      // 路径长度
int num[MAXV];     // 最短路径数量
int d[MAXV];     // 最短路径距离
int G[MAXV][MAXV]; // 邻接矩阵
bool vis[MAXV] = { false };

unordered_map<int, string> intToString; // loc - name
unordered_map<string, int> stringToInt; // name - loc

void Dijkstra(int s) {
    fill(pt, pt + MAXV, 0);
    fill(wt, wt + MAXV, 0);
    fill(num, num + MAXV, 0);
    fill(d, d + MAXV, INF);
    d[s] = 0;
    wt[s] = weight[s];
    num[s] = 1;
    pt[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v] = u;
                    pt[v] = pt[u] + 1;
                    num[v] = num[u];
                    wt[v] = wt[u] + weight[v];
                } else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if (wt[u] + weight[v] > wt[v]) {
                        pre[v] = u;
                        pt[v] = pt[u] + 1;
                        wt[v] = wt[u] + weight[v];
                    } else if (wt[v] == wt[u] + weight[v]) {
                        double vAvg = 1.0 * wt[v] / pt[v];
                        double uAvg = 1.0 * (wt[u] + weight[v]) / (pt[u] + 1);
                        if (uAvg > vAvg) {
                            pre[v] = u;
                            pt[v] = pt[u] + 1;
                        }
                    }
                }
            }
        }
    }
}

void DFS(string s, string e) {
    if (s == e) {
        cout << s;
        return;
    }
    DFS(s, intToString[pre[stringToInt[e]]]);
    cout << "->" << e;
}

int main() {
    fill(G[0], G[0] + MAXV * MAXV, INF);
    cin >> n >> k >> start;
    weight[0] = 0;
    intToString[0] = start;
    stringToInt[start] = 0;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> city >> w;
        weight[i] = w;
        intToString[i] = city;
        stringToInt[city] = i;
    }
    for (int i = 0; i < k; ++i) {
        cin >> c1 >> c2 >> w;
        u = stringToInt[c1];
        v = stringToInt[c2];
        G[u][v] = G[v][u] = w;
    }
    Dijkstra(0);
    int rom = stringToInt["ROM"];
    printf("%d %d %d %d\n", num[rom], d[rom], wt[rom], wt[rom] / pt[rom]);
    DFS(start, "ROM");
    return 0;
}
