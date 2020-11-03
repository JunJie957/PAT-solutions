#include <iostream>
using namespace std;
int main() {
    long int k, a, b, c;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%ld%ld%ld", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
