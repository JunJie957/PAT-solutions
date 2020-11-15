#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, ans = 0;;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + ans; j < n; ++j) {
            if (nums[j] <= nums[i] * p) {
                ans = max(ans, j - i + 1);
            } else {
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
