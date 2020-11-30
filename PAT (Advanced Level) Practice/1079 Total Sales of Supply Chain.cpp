#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node {
	int data;
	vector<int> child;
};

int n, k, child;
double p, r, sum = 0;
vector<node> tree;
void DFS(int index, int depth) {
	if (tree[index].child.empty()) {
		sum += p * pow(1 + r / 100, depth) * tree[index].data;
		return;
	}
	for (int i = 0; i < tree[index].child.size(); ++i) {
		DFS(tree[index].child[i], depth + 1);
	}
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	tree.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &child);
			tree[i].data = child;
		} else {
			for (int j = 0; j < k; ++j) {
				scanf("%d", &child);
				tree[i].child.emplace_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f", sum);
	return 0;
} 
