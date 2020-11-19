#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    int s = sqrt(n);
    for (int i = 2; i <= s; ++i) 
        if (n % i == 0) return false;
    return true;
}
int main() {
    int m, n, num;
    scanf("%d%d", &m, &n);
    while (!isPrime(m)) ++m;
    unordered_set<int> us;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        int loc = num % m;
        if (i != 0) printf(" ");
        if (us.find(loc) == us.end()) {
            printf("%d", loc);
            us.emplace(loc);
        } else {
            bool flag = true;
            for (int j = 1; j < m; ++j) {
                loc = (num + j * j) % m; // 平方探测法，过分！！！ 
                if (us.find(loc) == us.end()) {
                    printf("%d", loc);
                    us.emplace(loc);
                    flag = false;
                    break;
                }
            }
            if (flag) printf("-");
        }
    }
    return 0;
}
