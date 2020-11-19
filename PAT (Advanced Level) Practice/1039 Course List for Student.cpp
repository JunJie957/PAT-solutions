#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	char name[5];
	int n, k, pos, num;
	scanf("%d%d", &n, &k);
	unordered_map<string, set<int>> um;
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &pos, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%s", name);
			um[name].emplace(pos);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		printf("%s %d", name, um[name].size());
		for (auto& iter : um[name]) printf(" %d", iter);
		printf("\n");
	}
	return 0;
}
