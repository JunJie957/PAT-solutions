#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;

    // 统计各字符出现次数
    unordered_map<char, int> um1;
    unordered_map<char, int> um2;

    // 计算 s1 的两倍
    int add = 0, ans = 0;
    for (int i = s1.size() - 1; i >= 0; --i) {
        um1[s1[i]]++; // 统计各字符出现的次数
        ans = (s1[i] - '0') * 2 + add;
        if (ans >= 10) {
            ans -= 10;
            add = 1;
        }
        else {
            add = 0;
        }
        s2 += to_string(ans);
    }
    if (add == 1) s2 += "1";
    reverse(s2.begin(), s2.end());

    // 统计s2中出现的字符个数
    for (const auto& iter : s2) {
        um2[iter]++;
    }

    // 总字符的数量不同，则直接为false
    if (um1.size() != um2.size()) {
        printf("No\n%s", s2.c_str());
        return 0;
    }

    // 某个字符的数量不同，则直接为false
    for (const auto& iter : um1) {
        if (iter.second != um2[iter.first]) {
            printf("No\n%s",s2.c_str());
            return 0;
        }
    }

    // 字符总数和各个字符出现的次数都相同，则为true
    printf("Yes\n%s", s2.c_str());

    return 0;
}
