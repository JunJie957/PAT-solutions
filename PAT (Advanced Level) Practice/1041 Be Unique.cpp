#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n, x;
    scanf("%d", &n);
    vector<int> v;
    unordered_map<int,int> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (++um[x] == 1) v.push_back(x);
    }

    for (auto& iter : v) {
        if (um[iter] == 1) {
            printf("%d", iter);
            return 0;
        }
    }
    printf("None");
    return 0;
}
