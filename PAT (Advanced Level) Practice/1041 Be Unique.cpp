#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n, num;
    scanf("%d", &n);
    vector<int> lists;
    unordered_map<int, int> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        if (++um[num] == 1) lists.emplace_back(num);
    }
    for (auto& iter : lists) {
        if (um[iter] == 1) {
            printf("%d", iter);
            return 0;
        }
    }
    printf("None");
    return 0;
}
