#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* �ж��Ƿ�Ϊ���Ĵ� */
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

    int len = num.size(), count = 0, add = 0; // add - ��λ
    while (!isPalindrome(num, len)) {
        /* ��ת�ַ��� */
        string rev = num;
        reverse(rev.begin(), rev.end());
        
        /* �����ۼӺ� */ 
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

        /* ��ӡ��� */
        printf("%s + %s = %s\n", num.c_str(), rev.c_str(), res.c_str());

        /* ������ֵ�ж��Ƿ�Ϊ���Ĵ� */
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
