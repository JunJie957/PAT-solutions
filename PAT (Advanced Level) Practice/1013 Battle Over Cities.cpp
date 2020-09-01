#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;  // 总的城市个数
int v[1010][1001];
bool visit[1010];

// dfs: 深度优先遍历，将j能够到达的点全部访问
void dfs(int a) {
    visit[a] = true;
    for (int i = 1; i <= n; ++i) {
        if (visit[i] == false && v[a][i] == 1) 
            dfs(i);
    }
}

int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);

    /* 记录能够互通的城市 */
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b); 
        v[a][b] = v[b][a] = 1;  
    }

    int count = 0;
    for (int i = 0; i < k; ++i) {
        fill(visit, visit + 1010, false);

        /* lost city */
        scanf("%d", &a); 
        visit[a] = true; 

        /* 访问剩余的所有城市 */
        for (int j = 1; j <= n; ++j) {
            if (visit[j] == false) {
                dfs(j);
                ++count;
            }
        }
        printf("%d\n", count - 1);
        count = 0;
    }
    return 0;
}
