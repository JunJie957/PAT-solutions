#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n, m, begin, end, tmp;
    scanf("%d", &n);
    vector<int> sums(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        sums[i + 1] = sums[i] + tmp;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &begin, &end);
        if (begin > end) swap(begin, end);
        printf("%d\n", min(sums[end - 1] - sums[begin - 1], sums.back() - sums[end - 1] + sums[begin - 1]));
    }
    return 0;
}
