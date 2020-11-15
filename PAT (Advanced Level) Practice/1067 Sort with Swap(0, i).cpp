#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> um;     // 记录全部位置信息
    unordered_map<int, int> miss;   // 记录错位信息, 不记录零位置上的，因为会单独判断
    int n, num, loc = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        um[num] = i;
        if (num == 0) loc = i;
        if (i != num && num != 0) miss[num] = i;
    }
    while (1) {
        if (loc == 0) { // 如果 0 处于 位置0 上
            if (miss.empty()) { // 错位信息为空，说明排序好了
                cout << cnt;
                return 0;
            }
            ++cnt; // 增加一次交换次数
            loc = miss.begin()->second;
            um[miss.begin()->first] = 0;
            miss.begin()->second = 0;
        }
        ++cnt;
        miss.erase(loc);
        loc = um[loc];
    }
    return 0;
}
