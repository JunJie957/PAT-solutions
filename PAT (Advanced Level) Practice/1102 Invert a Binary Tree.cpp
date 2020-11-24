#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	node* lchild;
	node* rchild;
	node(int i) :data(i), lchild(nullptr), rchild(nullptr) {};
};

bool f1 = true, f2 = true;
void InOrder(node* root) {
	if (root == nullptr) return;
	InOrder(root->lchild);
	f1 ? f1 = false : printf(" ");
	printf("%d", root->data);
	InOrder(root->rchild);
}

void LayerOrder(node* root) {
	queue<node*> q;
	q.emplace(root);
	while (!q.empty()) {
		node* cur = q.front();
		q.pop();
		f2 ? f2 = false : printf(" ");
		printf("%d", cur->data);
		if (cur->lchild) q.emplace(cur->lchild);
		if (cur->rchild) q.emplace(cur->rchild);
	}
}

int main() {
	int n, root = 0;
	scanf("%d", &n);
	getchar();
	vector<node*> list(n);
	for (int i = 0; i < n; ++i) {
		list[i] = new node(i);
		root += i;
	}
	char left, right;
	for (int i = 0; i < n; ++i) {
		scanf("%c %c", &left, &right);
		getchar();
		if (left != '-') {
			list[i]->rchild = list[left - '0'];
			root -= left - '0';
		}
		if (right != '-') {
			list[i]->lchild = list[right - '0'];
			root -= right - '0';
		}
	}
	LayerOrder(list[root]);
	printf("\n");
	InOrder(list[root]);
	return 0;
}
