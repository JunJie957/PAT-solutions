#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string ans;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end(), [](string& a, string& b) { return a + b < b + a; });
    for (auto& iter : nums) ans += iter;
    while (ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
    cout << ans;
    return 0;
}
