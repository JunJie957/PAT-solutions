#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<double>> moonCake(n, vector<double>(3, 0));
    for (int i = 0; i < n; ++i) scanf("%lf", &moonCake[i][0]);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &moonCake[i][1]);
        moonCake[i][2] = moonCake[i][1] / moonCake[i][0];
    }
    sort(moonCake.begin(), moonCake.end(), [](vector<double>& m1, vector<double>& m2) { return m1[2] > m2[2]; });
    double res = 0;
    for (auto& iter : moonCake) {
        if (m > iter[0]) {
            m -= iter[0];
            res += iter[1];
        } else {
            res += m * iter[2];
            break;
        }
    }
    printf("%.2f", res);
    return 0;
}
