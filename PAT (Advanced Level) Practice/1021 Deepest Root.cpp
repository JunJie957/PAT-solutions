#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, maxheight = 0;
set<int> s;
vector<int> temp;
vector<vector<int>> v;
bool visit[10010] = { false };

// 深度优先遍历
void dfs(int node, int height) {
    if (height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if (height == maxheight) {
        temp.push_back(node);
    }
    visit[node] = true;
    for (int i = 0; i < v[node].size(); ++i) {
        if (visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n + 1);

    // 构建一颗树
    int a, b, cnt = 0, s1 = 0;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    // 深度优先遍历
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            dfs(i, 1);
            if (i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for (auto& iter : temp)  s.emplace(iter);
            }
            ++cnt;
        }
    }

    if (cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for (auto& iter : temp) s.emplace(iter);
        for (auto& iter : s)  printf("%d\n", iter);
    }
    return 0;
}
