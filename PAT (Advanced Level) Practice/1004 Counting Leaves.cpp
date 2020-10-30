#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maxDepth = 0;
vector<int> book(100, 0);
unordered_map<int, vector<int>> um;

void dfs(int index, int depth) {
    auto iter = um.find(index);
    if (iter == um.end()) {
        ++book[depth];
        maxDepth = max(maxDepth, depth);
    } else {
        for (int i = 0; i < iter->second.size(); ++i) {
            dfs(iter->second[i], depth + 1);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int id, k, children;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &children);
            um[id].emplace_back(children);
        }
    }

    dfs(1, 0);

    for (int i = 0; i <= maxDepth; ++i) {
        if (i != 0) printf(" ");
        printf("%d", book[i]);
    }
    return 0;
}
