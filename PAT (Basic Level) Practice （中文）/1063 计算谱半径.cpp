#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double a, b, res, max = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &a, &b);
        res = sqrt((a * a) + (b * b));
        res > max ? max = res : 0;
    }
    printf("%.2lf", max);
    return 0;
}
