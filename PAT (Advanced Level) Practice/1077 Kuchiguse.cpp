#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n); getchar();
    string str, res;
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if (i == 0) {
            res = str;
        } else {
            int j = res.size() - 1, k = str.size() - 1;
            for (; k >= 0; --k) {
                if (j >= 0 && str[k] == res[j]) {
                    --j;
                } else {
                    res = res.substr(j + 1);
                    break;
                }
            }
        }
    }

    if (!res.empty()) {
        printf("%s", res.c_str());
    } else {
        printf("nai");
    }
    return 0;
}
