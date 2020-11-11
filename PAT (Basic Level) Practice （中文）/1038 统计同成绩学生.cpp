#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n, score;
    scanf("%d", &n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &score);
        ++um[score];
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &score);
        if (i != 0) printf(" ");
        printf("%d", um[score]);
    }
    return 0;
}
