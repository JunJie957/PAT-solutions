#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    int s = sqrt(n);
    for (int i = 2; i <= s; ++i)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 2, j = 0, cnt = 0, flag = 0;
    while (cnt < m) {
        if (isPrime(i) && ++cnt >= n) {
            if (j > 0 && j % 10 == 0) {
                printf("\n");
                flag = 0;
            }
            if (flag) printf(" ");
            else flag = 1;
            printf("%d", i);
            ++j;
        }
        ++i;
    }
    return 0;
}
