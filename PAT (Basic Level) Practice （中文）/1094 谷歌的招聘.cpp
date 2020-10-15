#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int l, k, num;
    string str, tmp;
    cin >> l >> k >> str;
    for (int i = 0; i <= l - k; ++i) {
        tmp = str.substr(i, k);
        if (isPrime(stoi(tmp))) {
            printf("%s", tmp.c_str());
            return 0;
        }
    }
    printf("404");
    return 0;
}
