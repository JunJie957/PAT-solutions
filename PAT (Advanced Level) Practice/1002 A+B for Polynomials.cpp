#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, m, cnt = 0;
    double k;
    map<int, double, greater<int>> um;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &m, &k);
        um[m] = k;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &m, &k);
        um[m] += k;
    }

    for (auto& iter : um) if (iter.second != 0) ++cnt;
    printf("%d", cnt);
    for (auto& iter : um) if (iter.second != 0) printf(" %d %0.1lf", iter.first, iter.second);
    return 0;
}
