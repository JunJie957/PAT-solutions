// 写法1 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct fractional {
    int n;      // 分子
    int d;      // 分母
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

// 写法2

#include <iostream>
using namespace std;
struct Number {
    long int a; // 分子
    long int b; // 分母
    Number() :a(0), b(1) {};
    bool operator=(Number& other) {
        this->a = other.a;
        this->b = other.b;
        return true;
    }
};
int main() {
    int n, x, y;
    scanf("%d", &n);
    Number sum, tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d/%d", &x, &y);
        tmp.b = sum.b * y;
        tmp.a = sum.a * y + sum.b * x;
        sum = tmp;
        for (int i = min(sum.a, sum.b); i >= 2; --i) {
            if (sum.a % i == 0 && sum.b % i == 0) {
                sum.a /= i, sum.b /= i;
                break;
            }
        }
    }
    if (sum.a % sum.b == 0) {
        printf("%d", sum.a / sum.b);
    } else if (sum.a > sum.b && sum.a % sum.b > 0) {
        printf("%d %d/%d", sum.a / sum.b, sum.a % sum.b, sum.b);
    } else {
        printf("%d/%d", sum.a, sum.b);
    }
    return 0;
} 
