#include <iostream>
using namespace std;
int main() {
    int n, a = 1, ans = 0;
    scanf("%d", &n);
    int left, cur, right;
    while (n / a != 0) {
        left = n / (a * 10);
        cur = n / a % 10;
        right = n % a;
        if (cur == 0) ans += left * a;
        else if (cur == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a *= 10;
    }
    printf("%d", ans);
    return 0;
}
