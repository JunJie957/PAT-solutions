#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int weight;
	vector<int> child;
};

int n, m, s;
vector<int> path;
vector<node> tree;
void DFS(int id, int num, int sum) {
	if (sum > s) return;
	if (sum == s) {
		if (!tree[id].child.empty()) return;
		for (int i = 0; i < num; ++i) {
			printf("%d%s", tree[path[i]].weight, i < num - 1 ? " " : "\n");
		}
	}
	for (int i = 0; i < tree[id].child.size(); ++i) {
		int child = tree[id].child[i];
		path[num] = child;
		DFS(child, num + 1, sum + tree[child].weight);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	tree.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tree[i].weight);
	}
	int id, k;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &id, &k);
		tree[id].child.resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &tree[id].child[j]);
		}
		sort(tree[id].child.begin(), tree[id].child.end(), [](int a, int b) {
			return tree[a].weight > tree[b].weight;
			});
	}
	path.resize(n, 0);
	DFS(0, 1, tree[0].weight);
	return 0;
}
