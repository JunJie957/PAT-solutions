#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    bool flag = false;
    for (int i = n; i >= 1; --i) {
        if (v[n - i] > i) {
            printf("%d", i);
            flag = true;
            break;
        }
    }
    if (!flag) printf("0");
    return 0;
}
