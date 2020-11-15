// 方法1：哈希表 
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n, m, s;
    scanf("%d%d", &n, &m);
    set<int> nums;
    unordered_map<int, int> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s);
        nums.emplace(s);
        um[s]++;
    }
    for (auto& i : nums) {
        auto iter = um.find(m - i);
        if (iter != um.end()) {
            if (iter->first != i || iter->second > 1) {
                printf("%d %d", i, iter->first);
                return 0;
            } 
        }
    }
    printf("No Solution");
    return 0;
}

// 方法2：双指针法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    int left = 0, right = n - 1, sum;
    while (left < right) {
        sum = nums[left] + nums[right];
        if (sum == m) {
            printf("%d %d", nums[left], nums[right]);
            return 0;
        } else if (sum > m) {
            --right;
        } else {
            ++left;
        }
    }
    printf("No Solution");
    return 0;
} 
