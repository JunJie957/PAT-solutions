#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    string s = "0123456789ABC";
    printf("#%c%c%c%c%c%c", s[r / 13], s[r % 13], s[g / 13], s[g % 13], s[b / 13], s[b % 13]);
    return 0;
}
