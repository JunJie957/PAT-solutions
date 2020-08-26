#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long int num, multiply;
    scanf("%ld", &num);
    
    int first = 0, len = 0, maxn = sqrt(num) + 1;
    for(int i = 2; i <= maxn; ++i) {
        multiply = 1;
        int j = i;
        for (; j <= maxn; ++j) {   // 通过 i 和 j 记录连续的因子个数
            multiply *= j;
            if (num % multiply != 0) break;
        }
        if (j - i > len) {
            len = j - i;
            first = i;
        }
    }

    if (len == 0) {
        printf("1\n%d", num);
    } else {
        printf("%d\n", len);
        for(int i = 0; i < len; ++i) {
            printf("%d", first + i);
            if (i != len - 1) printf("*");
        }
    }
    return 0;
}
