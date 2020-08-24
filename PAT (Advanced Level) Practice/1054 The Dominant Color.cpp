#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int m, n, temp;
    scanf("%d%d", &m, &n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &temp);
            if (++um[temp] > n * m / 2) { // 统计所有颜色及其出现次数
                printf("%d", temp);
                return 0;
            }
        }
    }
    return 0;
}
