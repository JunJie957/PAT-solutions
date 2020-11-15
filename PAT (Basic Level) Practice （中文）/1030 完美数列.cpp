#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, result = 0;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + result; j < n; ++j) {
            if (v[j] <= v[i] * p) {
                result = max(result, j - i + 1);
            } else {
                break;
            }
        }
    }
    printf("%d", result);
    return 0;
}
