#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdlib.h>
#include <memory>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXV = 1030;
const int INF = 1000000000;

int n, m, k, DS, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = { false };

void Dijkstra(int s) {
    memset(vis,false,sizeof(vis));
    fill(d, d + MAXV, INF);
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
        for (int v = 1; v <= n + m; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}

int getID(string s) {
    if (s[0] != 'G') return stoi(s); 
    return n + stoi(s.substr(1));
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &DS);
    int u, v, w;
    string s1, s2;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 0; i < k; ++i) {
        cin >> s1 >> s2 >> w;
        u = getID(s1);
        v = getID(s2);
        G[u][v] = G[v][u] = w;
    }
    int ansID = -1;
    double ansDis = -1, ansAvg = INF;
    for (int i = n + 1; i <= n + m; ++i) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int j = 1; j <= n; ++j) {
            if (d[j] > DS) {
                minDis = -1;
                break;
            }
            if (d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if (minDis == -1) continue;
        if (minDis > ansDis) {
            ansID = i;
            ansDis = minDis;
            ansAvg = avg;
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
