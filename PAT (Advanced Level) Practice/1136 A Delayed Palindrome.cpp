#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 判断是否为回文串 */
bool isPalindrome(string& num,int& len) {
    if (num.compare("0") == 0) return true;
    int i = 0, j = len - 1;
    do {
        if (num[i] != num[j]) return false;
    } while (++i < --j);
    return true;
}

int main()
{
    string num;
    cin >> num;

    int len = num.size(), count = 0, add = 0; // add - 进位
    while (!isPalindrome(num, len)) {
        /* 反转字符串 */
        string rev = num;
        reverse(rev.begin(), rev.end());
        
        /* 计算累加和 */ 
        add = 0;
        string res;
        for (int i = len - 1; i >= 0; --i) {
            int sum = (num[i] - '0') + (rev[i] - '0') + add;
            if (sum >= 10) {
                add = 1; sum -= 10;
            } else {
                add = 0;
            }
            res += to_string(sum);
            if (i == 0 && add == 1) res += "1";
        }
        reverse(res.begin(), res.end());

        /* 打印输出 */
        printf("%s + %s = %s\n", num.c_str(), rev.c_str(), res.c_str());

        /* 继续赋值判断是否为回文串 */
        num = res;
        len = num.length();
        if (++count == 10) {
            printf("Not found in 10 iterations.");
            return 0;
        }
    }
    printf("%s is a palindromic number.", num.c_str());
    return 0;
}
