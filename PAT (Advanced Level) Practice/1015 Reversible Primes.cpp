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

        // ���n��������ֱ���и�
        if (!isPrime(n)) {
            printf("No\n");
            continue;
        }

        // �� n ת��Ϊ�������е� d ������ʽ
        vector<int> arr;
        while (n != 0) {
            arr.push_back(n % d);
            n /= d;
        }
        
        // �� d ���� ת��Ϊ 10 ���ƣ������������ж�
        for (int i = arr.size() - 1, j = 0; i >= 0; --i,++j)
            n += pow(d,j) * arr[i];

        printf("%s\n", isPrime(n) ? "Yes" : "No");
    }
    return 0;
}
