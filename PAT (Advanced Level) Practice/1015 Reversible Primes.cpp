#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, d;
    while (scanf("%d", &n) != EOF) {

        if (n < 0) break;
        scanf("%d", &d);

        // 如果n非素数，直接判负
        if (!isPrime(n)) {
            printf("No\n");
            continue;
        }

        // 将 n 转化为倒序排列的 d 进制形式
        vector<int> arr;
        while (n != 0) {
            arr.push_back(n % d);
            n /= d;
        }
        
        // 将 d 进制 转化为 10 进制，并进行素数判断
        for (int i = arr.size() - 1, j = 0; i >= 0; --i,++j)
            n += pow(d,j) * arr[i];

        printf("%s\n", isPrime(n) ? "Yes" : "No");
    }
    return 0;
}
