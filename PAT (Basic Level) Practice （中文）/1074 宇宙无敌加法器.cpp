#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string a, b, c, ans;
    cin >> a >> b >> c;

    // 将 b 和 c 补齐，跟 a 的长度相同
    string zero1(a.length() - b.length(), '0');
    b = zero1 + b;
    string zero2(a.length() - c.length(), '0');
    c = zero2 + c;
    
    int loc = a.length() - 1, carry = 0, sum, rule;
    while (loc >= 0) {
        sum = b[loc] - '0' + c[loc] - '0' + carry;
        rule = (a[loc] == '0') ? 10 : a[loc] - '0';
        ans += to_string(sum % rule);
        carry = sum / rule;
        --loc;
    }
    if (carry != 0) ans += '1';
    reverse(ans.begin(), ans.end());
    bool flag = false;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] != '0' || flag == true) {
            flag = true;
            cout << ans[i];
        }
    }
    if(!flag) cout << 0;
    return 0;
}
