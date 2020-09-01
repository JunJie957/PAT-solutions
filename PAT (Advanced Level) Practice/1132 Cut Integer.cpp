#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, num, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        a = stoi(to_string(num).substr(0, to_string(num).length() / 2));
        b = stoi(to_string(num).substr(to_string(num).length() / 2));
        if (a * b != 0 && num % (a * b) == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
