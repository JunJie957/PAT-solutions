#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;

    double x = r1 * cos(p1) * r2 * cos(p2) - r1 * sin(p1) * r2 * sin(p2);
    double y = r1 * sin(p1) * r2 * cos(p2) + r1 * cos(p1) * r2 * sin(p2);

    // 防止四舍五入为 -0.00
    if (x >= -0.005 && x < 0) x = 0.00;
    if (y >= -0.005 && y < 0) y = 0.00;
       
    if (y < 0)  printf("%0.2lf%.02fi", x, y);
    else printf("%0.2lf+%0.2lfi", x, y);

    return 0;
}


