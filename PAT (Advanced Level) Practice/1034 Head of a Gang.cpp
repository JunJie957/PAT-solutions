#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<string, int> stringToInt;
unordered_map<int, string> intToString;
map<string, int> ans;
int idNumber = 1, k;

int stoifunc(string s) {
    if (stringToInt.find(s) != stringToInt.end()) {
        return stringToInt[s];
    }
    else {
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    }
}

int G[2010][2010] = { 0 }, weight[2010] = { 0 };
bool visit[2010] = { false };

// 深度优先遍历：递归
void dfs(int u, int& head, int& numMember, int& totalweight) {
    visit[u] = true;
    ++numMember;
    if (weight[u] > weight[head]) // 如果当前节点权值大于头目的权值，则交换头目
        head = u;
    for (int v = 1; v < idNumber; v++) {
        if (G[u][v] > 0) {
            totalweight += G[u][v];     // 计算此首节点的权值之和
            G[u][v] = G[v][u] = 0;      // 删除此条边
            if (visit[v] == false)      
                dfs(v, head, numMember, totalweight); // 递归访问能到达的下一个节点
        }
    }
}

// 遍历整个图
void dfsTrave() {
    int head, numMember, totalWeight;
    for (int i = 0; i < idNumber; ++i) {
        if (visit[i] == false) {
            head = i, numMember = 0, totalWeight = 0;
            dfs(i, head, numMember, totalWeight);
            if (numMember > 2 && totalWeight > k) {
                ans[intToString[head]] = numMember;
            }
        }
    }
}

int main() {
    int n, w;
    scanf("%d%d", &n, &k);
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }

    dfsTrave();

    printf("%d\n", ans.size());
    for (const auto& iter : ans)
        printf("%s %d\n", iter.first.c_str(), iter.second);
    return 0;
}
