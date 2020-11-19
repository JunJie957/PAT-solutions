#include <iostream>
#include <math.h>
#include <map>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = sqrt(n);
    for (int i = 2; i <= sqr; ++i)
        if (n % i == 0) return false;
    return true;
}
int main() {
    long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    long int sqr = sqrt(n);
    map<int, int> m;
    if (n == 1) m[1] = 1;
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0 && isPrime(i)) {
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            m[i] = cnt;
        }
        if (n == 1) break;
    }
    if (n != 1) m[n]++;
    bool flag = true;
    for (auto& iter : m) {
        if (flag) flag = false;
        else printf("*");
        printf("%d", iter.first);
        if (iter.second > 1) printf("^%d", iter.second);
    }
    return 0;
}
