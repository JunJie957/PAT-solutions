#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdlib.h>
#include <memory>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXV = 1020;
const int INF = 1000000000;

struct node {
    int v;
    int dis;
    node(int a, int b) :v(a), dis(b) {}
};

 string s1, s2;
int n, m, k, SD, u, v, w;
int d[MAXV];
bool vis[MAXV];
vector<node> adj[MAXV];

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    fill(vis, vis + MAXV, false);
    d[s] = 0;
    for (int i = 0; i < n + m; ++i) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].v;
            int dis = adj[u][j].dis;
            if (vis[v] == false && dis + d[u] < d[v]) {
                d[v] = d[u] + dis;
            }
        }
    }
}

int getID(string s) {
    if (s[0] != 'G') return stoi(s);
    return n + stoi(s.substr(1));
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &SD);
    for (int i = 0; i < k; ++i) {
        cin >> s1 >> s2 >> w;
        u = getID(s1);
        v = getID(s2);
        adj[u].emplace_back(node(v, w));
        adj[v].emplace_back(node(u, w));
    }
    int ansID = -1;
    double ansDis = -1, ansAvg = 0;
    for (int i = n + 1; i <= n + m; ++i) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int j = 1; j <= n; ++j) {
            if (d[j] > SD) {
                minDis = -1;
                break;
            }
            if (d[j] < minDis) minDis = d[j];
            avg += d[j] * 1.0 / n;
        }
        if (minDis == -1) continue;
        if (minDis > ansDis) {
            ansID = i;
            ansAvg = avg;
            ansDis = minDis;
        } else if (minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }
    if (ansID == -1) printf("No Solution");
    else {
        printf("G%d\n", ansID - n);
        printf("%.1f %.1f", ansDis, ansAvg);
    }
    return 0;
}
