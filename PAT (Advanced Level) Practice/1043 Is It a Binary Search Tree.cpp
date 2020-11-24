#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* lchild;
	node* rchild;
	node(int v) :data(v), lchild(nullptr), rchild(nullptr) {};
};

void InsertNode(node*& root, int& val) {
	if (root == nullptr) {
		root = new node(val);
		return;
	}
	if (val >= root->data) {
		InsertNode(root->rchild, val);
	} else {
		InsertNode(root->lchild, val);
	}
}

vector<int> origin, pre, preM, post, postM;
void PreOrder(node* root) {
	if (root == nullptr) return;
	pre.emplace_back(root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void PreOrderMirror(node* root) {
	if (root == nullptr) return;
	preM.emplace_back(root->data);
	PreOrderMirror(root->rchild);
	PreOrderMirror(root->lchild);
}

void PostOrder(node* root) {
	if (root == nullptr) return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	post.emplace_back(root->data);
}

void PostOrderMirror(node* root) {
	if (root == nullptr) return;
	PostOrderMirror(root->rchild);
	PostOrderMirror(root->lchild);
	postM.emplace_back(root->data);
}

int main() {
	int n;
	scanf("%d", &n);
	origin.resize(n);
	node* root = nullptr;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &origin[i]);
		InsertNode(root, origin[i]);
	}
	PreOrder(root);
	PreOrderMirror(root);
	if (origin == pre) {
		printf("YES\n");
		PostOrder(root);
		for (int i = 0; i < n; ++i) {
			if (i != 0) printf(" ");
			printf("%d", post[i]);
		}
	} else if (origin == preM) {
		printf("YES\n");
		PostOrderMirror(root);
		for (int i = 0; i < n; ++i) {
			if (i != 0) printf(" ");
			printf("%d", postM[i]);
		}
	} else {
		printf("NO");
	}
	return 0;
}
