#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int sqr = sqrt(n), len = 0, begin = n;
    for (int i = 2; i <= sqr; ++i) {
        int j = i, multi = 1;;
        while (j <= sqr) {
            multi *= j;
            if (n % multi != 0) break;
            ++j;
        }
        if (j - i > len) {
            len = j - i;
            begin = i;
        }
    }
    if (len == 0) {
        printf("1\n%ld", n);
    } else {
        printf("%d\n", len);
        for (int i = 0; i < len; ++i) {
            if (i != 0) printf("*");
            printf("%d", begin + i);
        }
    }
    return 0;
}
