#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int main() {
	int n, m, num, k, begin, end;
	scanf("%d", &n);
	vector<unordered_set<int>> v(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &num);
			v[i].emplace(num);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &begin, &end);
		num = 0;
		for (auto& iter : v[begin]) num += v[end].count(iter);
		printf("%.1f%%\n", (double)num / (v[begin].size() + v[end].size() - num) * 100);
	}
	return 0;
}
