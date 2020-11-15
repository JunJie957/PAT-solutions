#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    // 数据输入
    long int n, m, loc = 0;
    scanf("%ld", &n);
    vector<long int> s1(n);
    for (int i = 0; i < n; ++i) scanf("%ld", &s1[i]);
    scanf("%ld", &m);
    vector<long int> s2(m);
    for (int i = 0; i < m; ++i) scanf("%ld", &s2[i]);

    // 下标位置
    if ((n + m) % 2 == 0) {
        loc = (n + m) / 2 - 1; 
    } else {
        loc = (n + m) / 2;
    }
    
    // 计算位置
    int i = 0, j = 0, cnt = -1;
    while (i < n && j < m) {
        if (s1[i] <= s2[j]) {
            if (++cnt == loc) {
                printf("%ld", s1[i]);
                return 0;
            }
            ++i;
        } else {
            if (++cnt == loc) {
                printf("%ld", s2[j]);
                return 0;
            }
            ++j;
        }
    }
    while (i < n) {
        if (++cnt == loc) {
            printf("%ld", s1[i]);
            return 0;
        }
        ++i;
    }
    while (j < n) {
        if (++cnt == loc) {
            printf("%ld", s2[j]);
            return 0;
        }
        ++j;
    }
    return 0;
}
