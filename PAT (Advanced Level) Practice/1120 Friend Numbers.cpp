#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <set>
#include <string>
using namespace std;

int main()
{
    int n, temp, sum;
    scanf("%d", &n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        scanf("%d", &temp);
        string str = to_string(temp);
        for (int i = 0; i < str.size(); ++i)
            sum += str[i] - '0';
        s.insert(sum);
    }

    printf("%d\n",s.size());
    bool first = true;
    for (auto& iter : s) {
        if (first) {
            printf("%d", iter);
            first = false;
        } else {
            printf(" %d", iter);
        }
    }
    return 0;
}
