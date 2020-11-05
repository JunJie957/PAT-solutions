#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    scanf("%d", &n);
    vector<int> nums(5, 0);
    int cnt1 = 0, cnt2 = 0, flag = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        if (m % 5 == 0 && m % 2 == 0) nums[0] += m;
        if (m % 5 == 1) {
            if (cnt1 == 0) { nums[1] += m; cnt1 = 1; flag = 1; }
            else { nums[1] -= m; cnt1 = 0; flag = 1; }
        }
        if (m % 5 == 2) ++nums[2];
        if (m % 5 == 3) { nums[3] += m; ++cnt2; }
        if (m % 5 == 4) nums[4] = max(m, nums[4]);
    }
    if (nums[0] == 0) printf("N");  else printf("%d", nums[0]);
    if (flag != 1)    printf(" N"); else printf(" %d", nums[1]);
    if (nums[2] == 0) printf(" N"); else printf(" %d", nums[2]);
    if (nums[3] == 0) printf(" N"); else printf(" %0.1f", (double)nums[3] / cnt2);
    if (nums[4] == 0) printf(" N"); else printf(" %d", nums[4]);
    return 0;
}
