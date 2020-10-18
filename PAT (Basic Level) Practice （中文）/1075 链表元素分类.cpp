#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    int next;
}list[100000];

vector<int> v[3];

int main() {
    int addr, n, k, loc, num;
    scanf("%d%d%d", &addr, &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &loc);
        scanf("%d%d", &list[loc].data, &list[loc].next);
    }

    while (addr != -1) {
        num = list[addr].data;
        if (num < 0) {
            v[0].emplace_back(addr);
        } else if (num >= 0 && num <= k) {
            v[1].emplace_back(addr);
        } else {
            v[2].emplace_back(addr);
        }
        addr = list[addr].next;
    }

    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if (flag) {
                printf("%05d %d ", v[i][j], list[v[i][j]]);
                flag = false;
            } else {
                printf("%05d\n%05d %d ", v[i][j], v[i][j], list[v[i][j]]);
            }
        }
    }
    printf("-1");
    return 0;
}
