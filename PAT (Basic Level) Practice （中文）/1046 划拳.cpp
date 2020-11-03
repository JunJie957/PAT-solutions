#include <iostream>
using namespace std;
int main() {
    int n, a, b, c, d, sum, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        sum = a + c;
        if (b != sum && d == sum) ++cnt1;
        if (b == sum && d != sum) ++cnt2;
    }
    printf("%d %d", cnt1, cnt2);
    return 0;
}
