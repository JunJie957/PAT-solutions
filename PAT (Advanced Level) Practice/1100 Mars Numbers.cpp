#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v1{ "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
vector<string> v2{  "   ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int main() 
{
    int n, num;
    scanf("%d", &n);
    getchar();
    
    string str;
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') { // 数字转为火星文
            num = stoi(str);
            if (num < 13) printf("%s\n", v1[num].c_str());
            else if (num % 13 == 0) printf("%s\n", v2[num/13].c_str());
            else printf("%s %s\n", v2[num / 13].c_str(), v1[num % 13].c_str());
        } else { // 火星文转为数字
            num = 0;
            string s1 = str.substr(0, 3), s2;
            if (str.length() > 4) s2 = str.substr(4, 3);
            for (int i = 1; i <= 12; ++i) {
                if (s1 == v1[i] || s2 == v1[i]) num += i;
                if (s1 == v2[i]) num += i * 13;
            }
            printf("%d\n", num);
        }
    }
    return 0;
}
