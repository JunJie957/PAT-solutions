#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main() {
    int count;
    string s;
    cin >> s >> count;
    for (int i = 1; i < count; ++i) {
        string tmp;
        for (int i = 0, j = 0; i < s.size(); i = j) {
            for (j = i; j < s.size() && s[i] == s[j]; ++j); // 统计相同字母的个数
            tmp += s[i] + to_string(j - i);
        }
        s = tmp;
    }
    cout << s;
    return 0;
}
