
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* lchild;
	node* rchild;
	node(int val):data(val), lchild(nullptr), rchild(nullptr) {};
};

vector<int> in;
vector<node*> tree;
void InOrder(node* root) {
	if (root == nullptr) return;
	InOrder(root->lchild);
	in.emplace_back(root->data);
	InOrder(root->rchild);
}

void LayerTraversal(node* root) {
	queue<node*> q;
	q.emplace(root);
	bool flag = true;
	while (!q.empty()) {
		node* cur = q.front();
		q.pop();
		flag ? flag = false : printf(" ");
		printf("%d", cur->data);
		if (cur->lchild) q.emplace(cur->lchild);
		if (cur->rchild) q.emplace(cur->rchild);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		tree.emplace_back(new node(i));
	}
	int left, right;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &left, &right);
		if (left != -1)  tree[i]->lchild = tree[left];
		if (right != -1) tree[i]->rchild = tree[right];
	}
	vector<int> order(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &order[i]);
	}
	sort(order.begin(), order.end());
	InOrder(tree[0]);
	for (int i = 0; i < n; ++i) {
		tree[in[i]]->data = order[i];
	}
	LayerTraversal(tree[0]);
	return 0;
}
