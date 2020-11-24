#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	vector<node*> child;
	node(int i) :data(i){};
};

void LayerOrder(node* root) {
	queue<vector<node*>> q;
	q.push({ root });
	int layer = 1, max_node = 0, layer_of_max = 1;
	while (!q.empty()) {
		vector<node*> cur = q.front();
		q.pop();
		if (cur.size() > max_node) {
			max_node = cur.size();
			layer_of_max = layer;
		}
		vector<node*> next_layer;
		for (int i = 0; i < cur.size(); ++i) {
			for (int j = 0; j < cur[i]->child.size(); ++j) {
				next_layer.emplace_back(cur[i]->child[j]);
			}
		}
		if (!next_layer.empty()) {
			q.emplace(next_layer);
			++layer;
		}
	}
	printf("%d %d", max_node, layer_of_max);
}
int main() {
	int n, m, num, k, child;
	scanf("%d%d", &n, &m);
	vector<node*> tree(n + 1);
	for (int i = 0; i <= n; ++i) 
		tree[i] = new node(i);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &num, &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &child);
			tree[num]->child.emplace_back(tree[child]);
		}
	}
	LayerOrder(tree[1]);
	return 0;
}
