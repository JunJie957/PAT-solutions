#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct fractional {
    int n;      // ·Ö×Ó
    int d;      // ·ÖÄ¸
    fractional():n(0),d(1) {};
};

void simple(int& a, int& b) {
    for (int i = a > b ? b : a; i >= 2; --i) {
        if (a % i == 0 && b % i == 0) {
            a /= i; b /= i; break;
        }
    }
    return;
}

fractional addTwoFractional(fractional& f1, fractional& f2) {
    fractional fra;
    fra.d = f1.d * f2.d;
    fra.n = (f1.n * f2.d) + (f2.n * f1.d);
    simple(fra.d, fra.n);
    return fra;
}

int main()
{
    int n;
    scanf("%d", &n);
    fractional temp, sum;
    for (int i = 0; i < n; ++i) { 
        scanf("%d/%d", &temp.n, &temp.d);
        sum = addTwoFractional(sum, temp);
    }
    
    if (sum.n % sum.d == 0) { 
        printf("%d", sum.n / sum.d);
    } else if (sum.n > sum.d) {
        printf("%d %d/%d", sum.n / sum.d, sum.n % sum.d, sum.d);
    } else {
        printf("%d/%d", sum.n, sum.d);
    }
    return 0;
}
