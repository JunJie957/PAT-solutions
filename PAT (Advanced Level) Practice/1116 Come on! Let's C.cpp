#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isPrime(int num) {
    int sqr = sqrt(num);
    if (num == 1) return false;
    for (int i = 2; i <= sqr; ++i)
        if (num % i == 0) return false;
    return true;
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    unordered_map<int, string> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        if (i == 0) {
            um[temp] = "Mystery Award";
        } else if (isPrime(i + 1)) {
            um[temp] = "Minion";
        } else {
            um[temp] = "Chocolate";
        }
    }
    scanf("%d", &n);
    unordered_set<int> check;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        printf("%04d: ", temp);
        if (um.find(temp) != um.end()) {
            if (check.find(temp) == check.end()) {
                printf("%s", um[temp].c_str());
                check.insert(temp);
            } else {
                printf("Checked");
            }
        } else {
            printf("Are you kidding?");
        }
        if (i != n - 1) printf("\n");
    }
    return 0;
}

