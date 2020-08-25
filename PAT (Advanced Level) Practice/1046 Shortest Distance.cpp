#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, temp, begin, end, sum = 0;
    scanf("%d", &n);
    vector<int> dis(n + 1, 0);
    for (int i = 1; i < n + 1; ++i) {
        scanf("%d", &temp);
        sum += temp;
        dis[i] = sum; // 记录路径之和
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &begin, &end);
        printf("%d\n", min(abs(dis[end - 1] - dis[begin - 1]), sum - (abs(dis[end - 1] - dis[begin - 1]))));
    }
    return 0;
}
