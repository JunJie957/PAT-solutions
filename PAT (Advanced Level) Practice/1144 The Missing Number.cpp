#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp;
    scanf("%d", &n);

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        if(tmp > 0) v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int size = v.size() - 1;
    for (int i = 0; i < size; ++i) {
        if (v[i + 1] - v[i] > 1) {
            printf("%d", v[i] + 1);
            return 0;
        }
    }

    if (v.empty()) printf("1");
    else printf("%d", v.back() + 1);
    return 0;
}
