#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 110;
struct node {
	int weight;
	vector<int> child;
}Node[MAXN];

int n, m, s;
int path[MAXN];
void DFS(int index, int numNode, int sum) {
	if (sum > s) return;
	if (sum == s) {
		if (!Node[index].child.empty()) return;
		for (int i = 0; i < numNode; ++i) {
			printf("%d%s", Node[path[i]].weight, i < numNode - 1 ? " " : "\n");
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); ++i) {
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + Node[child].weight);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; ++i) scanf("%d", &Node[i].weight);
	int id, k, child;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &child);
			Node[id].child.emplace_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), [](int& a, int& b) {
			return Node[a].weight > Node[b].weight; });
	}
	path[0] = 0;
	DFS(0, 1, Node[0].weight); 
	return 0;
}
