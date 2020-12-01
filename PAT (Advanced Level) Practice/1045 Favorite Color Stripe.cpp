#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxc = 210;
const int maxn = 10010;
vector<int> hashTable(maxc, -1);
int A[maxn], dp[maxn];

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m); 
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        hashTable[x] = i;
    }
    int L, num = 0;
    scanf("%d", &L);
    for (int i = 0; i < L; ++i) {
        scanf("%d", &x);
        if (hashTable[x] >= 0) {
            A[num++] = hashTable[x];
        }
    }
    // LIS:最长不下降子序列
    int ans = -1;
    for (int i = 0; i < num; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (A[j] <= A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
