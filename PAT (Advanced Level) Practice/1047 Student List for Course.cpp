#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	char name[5];
	int num, course;
	unordered_map<int, vector<string>> um;
	for (int i = 0; i < n; ++i) {
		scanf("%s%d", name, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &course);
			um[course].emplace_back(name);
		}
	}
	for (int i = 1; i <= k; ++i) {
		printf("%d %d\n", i, um[i].size());
		sort(um[i].begin(), um[i].end());
		for (auto& iter : um[i]) {
			printf("%s\n", iter.c_str());
		}
	}
	return 0;
}
