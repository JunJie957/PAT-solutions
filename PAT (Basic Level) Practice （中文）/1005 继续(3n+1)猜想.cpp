#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main() {
    int k;
    scanf("%d", &k);
    vector<int> nums(k, 0);
    for (int i = 0; i < k; ++i) scanf("%d", &nums[i]);
    unordered_set<int> record;
    set<int, greater<int>> ans{ nums.begin(),nums.end() };
    for (int i = 0; i < k; ++i) {
        if (record.count(nums[i])) {
            ans.erase(nums[i]);
            continue;
        }
        record.emplace(nums[i]);
        while (nums[i] != 1) {
            if (nums[i] % 2 == 0) {
                nums[i] /= 2;
            } else {
                nums[i] = (nums[i] * 3 + 1) / 2;
            }
            ans.erase(nums[i]);
            if (record.count(nums[i])) break;
            record.emplace(nums[i]);
        }
    }
    for (auto& iter : ans) {
        if (iter != *ans.begin()) cout << " ";
        cout << iter;
    }
    return 0;
}
