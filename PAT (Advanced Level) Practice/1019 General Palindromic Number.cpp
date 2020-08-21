#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, b;
    vector<int> v, rev;
    scanf("%d%d", &n, &b);

    do {
        v.push_back(n % b);
        n /= b;
    } while (n != 0);

    rev = v;
    reverse(v.begin(), v.end());

    if (rev == v) printf("Yes\n");
    else printf("No\n");

    int size = v.size();
    printf("%d", v[0]);
    for (int i = 1; i < size; ++i) {
        printf(" %d", v[i]);
    }
    return 0;
}
