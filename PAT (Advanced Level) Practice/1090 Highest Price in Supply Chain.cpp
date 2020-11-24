#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maxDepth = 0, cnt;
vector<vector<int>> child;
void DFS(int index, int depth) {
	if (child[index].empty()) {
		if (depth > maxDepth) {
			maxDepth = depth;
			cnt = 1;
		} else if (depth == maxDepth) {
			++cnt;
		}
	}
	for (int i = 0; i < child[index].size(); ++i) {
		DFS(child[index][i], depth + 1);
	}
}
int main() {
	int n, father, root;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	child.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &father);
		if (father != -1) {
			child[father].emplace_back(i);
		} else {
			root = i;
		}
	}
	DFS(root, 0);
	printf("%.2f %d", p * pow(1 + r / 100, maxDepth), cnt);
	return 0;
} 
