
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    int s = sqrt(n);
    for (int i = 2; i <= s; ++i) 
        if (n % i == 0) return false;
    return true;
}
int main() {
    int n, d;
    while (1) {
        scanf("%d", &n);
        if (n < 0) return 0;
        scanf("%d", &d);
        if (!isPrime(n)) {
            printf("No\n");
            continue;
        }
        string r;
        while (n != 0) {
            r += '0' + (n % d);
            n /= d;
        }
        for (int i = r.size() - 1, j = 0; i >= 0; --i, ++j)
            n += pow(d, j) * (r[i] - '0');
        printf("%s\n", isPrime(n) ? "Yes" : "No");
    }
    return 0;
}
