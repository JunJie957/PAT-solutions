#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool isPrime(string& s) {
    int num = stoi(s), sqr = sqrt(num);
    for (int i = 2; i <= sqr; ++i) if (num % i == 0) return false;
    return true;
}

int main()
{
    int l, k;
    scanf("%d%d\n", &l, &k);
    string s, temp;
    getline(cin, s);

    for (int i = 0; i <= l - k; ++i) {
        temp = s.substr(i, k);
        if (isPrime(temp)) {
            printf("%s", temp.c_str());
            return 0;
        }
    }
    printf("404");
    return 0;
}
