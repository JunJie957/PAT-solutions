#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
	
	int l = -1;
	vector<int> lefts;
	lefts.emplace_back(l);
	for (int i = 0; i < n; ++i) {
		l = max(nums[i], l);
		lefts.emplace_back(l);
	}

	int r = nums.back() + 1;
	vector<int> rights;
	rights.emplace_back(r);
	for (int i = n - 1; i >= 0; --i) {
		r = min(nums[i], r);
		rights.emplace_back(r);
	}

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (nums[i] > lefts[i] && nums[i] < rights[n - 1 - i]) {
			ans.emplace_back(nums[i]);
		}
	}
    printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
    printf("\n");
	return 0;
}
