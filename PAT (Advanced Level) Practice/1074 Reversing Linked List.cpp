#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
	int head, n, k;
	scanf("%d%d%d", &head, &n, &k);

	int data, addr, next;
	unordered_map<int, pair<int, int>> um;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &addr, &data, &next);
		um[addr] = make_pair(data, next);
	}

	vector<pair<int, int>> v;
	vector<pair<int, int>> ans;
	while (head != -1) {
		v.push_back({ um[head].first, head });
		head = um[head].second;
		if (v.size() == k) {
			reverse(v.begin(), v.end());
			for (auto& iter : v) ans.emplace_back(iter);
			v.clear();
		}
	}
	for (auto& iter : v) ans.emplace_back(iter);
	for (int i = 0; i < ans.size() - 1; ++i) {
		printf("%05d %d %05d\n", ans[i].second, ans[i].first, ans[i + 1].second);
	}
	printf("%05d %d -1", ans.back().second, ans.back().first);
	return 0;
}
