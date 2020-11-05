#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
    int n, m, cnt = 0;
    double k;
    unordered_map<int, double> um;
    map<int, double, greater<int>> res;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &m, &k);
        um[m] = k;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &m, &k);
        for (auto& iter : um) res[m + iter.first] += iter.second * k;
    }

    for (auto& iter : res) if (iter.second != 0) ++cnt;
    printf("%d", cnt);
    for (auto& iter : res) if (iter.second != 0) printf(" %d %0.1lf", iter.first, iter.second);
    return 0;
}
