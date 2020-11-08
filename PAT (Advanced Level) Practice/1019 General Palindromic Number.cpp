#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	vector<int> nums;
	while (n != 0) {
		nums.emplace_back(n % b);
		n /= b;
	}
	int left = 0, right = nums.size() - 1, flag = true;
	while (left < right) {
		if (nums[left++] != nums[right--]) {
			printf("No\n");
			flag = false;
			break;
		}
	}
	if (flag) printf("Yes\n");
	for (int i = nums.size() - 1; i >= 0; --i) {
		printf("%d", nums[i]);
		if (i != 0) printf(" ");
	}
	return 0;
}
