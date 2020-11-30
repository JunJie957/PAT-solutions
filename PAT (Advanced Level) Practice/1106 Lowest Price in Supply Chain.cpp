#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, k, child, minDepth, cnt = 0;
double p, r;
vector<vector<int>> tree;
void DFS(int index, int depth) {
	if (tree[index].empty()) {
		if (depth < minDepth) {
			minDepth = depth;
			cnt = 1;
		} else if (depth == minDepth) {
			++cnt;
		}
		return;
	}
	for (int i = 0; i < tree[index].size(); ++i) {
		DFS(tree[index][i], depth + 1);
	}
}

int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	tree.resize(n);
	minDepth = n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &child);
			tree[i].emplace_back(child);
		}
	}
	DFS(0, 0);
	printf("%.4lf %d", p * pow(1 + r / 100, minDepth), cnt);
	return 0;
}
