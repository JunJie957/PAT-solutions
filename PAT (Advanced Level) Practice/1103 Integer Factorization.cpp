#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, k, p, maxSumOfIndex = -1;
vector<int> path, ans, temp;;
void DFS(int index, int numK, int sum, int maxIndexSum) {
	if (sum == n && numK == k) {
		if (maxIndexSum > maxSumOfIndex) {
			ans = temp;
			maxSumOfIndex = maxIndexSum;
			return;
		}
	}
	if (sum > n || numK > k) return;
	if (index > 0) {
		temp.emplace_back(index);
		DFS(index, numK + 1, sum + path[index], maxIndexSum + index);
		temp.pop_back();
		DFS(index - 1, numK, sum, maxIndexSum);
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0; i <= n; ++i) {
		if (pow(i, p) <= n) {
			path.emplace_back(pow(i, p));
		} else {
			break;
		}
	}
	DFS(path.size() - 1, 0, 0, 0);
	if (maxSumOfIndex == -1) printf("Impossible");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); ++i) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
} 
