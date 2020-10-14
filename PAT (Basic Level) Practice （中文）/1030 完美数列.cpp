#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, result = 0;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + result; j < n; ++j) {
            if (nums[j] <= nums[i] * p) {
                result = max(result, j - i + 1);
            } else {
                break;
            }
        }
    }
    printf("%d", result);
    return 0;
}
