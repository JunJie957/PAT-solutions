#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int m, x, y;
void myPrintf(double val) {
    if (m == val)printf(" Ping");
    else if (m < val) printf(" Cong");
    else printf(" Gai");
}

int main() {
    scanf("%d%d%d", &m, &x, &y);
    for (int a = 99; a >= 10; --a) {
        int b = a % 10 * 10 + a / 10;
        double c = abs(a - b) * 1.0 / x;
        if (b == c * y) {
            printf("%d", a);
            myPrintf(a); myPrintf(b); myPrintf(c);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
