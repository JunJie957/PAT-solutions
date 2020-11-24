#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct node {
	int data;
	node* lchild;
	node* rchild;
};
vector<int> pre, in;
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) return nullptr;
	node* root = new node;
	root->data = pre[preL];
	int k, num_left;
	for (k = inL; k <= inR; ++k) {
		if (in[k] == root->data) {
			num_left = k - inL;
			break;
		}
	}
	root->lchild = create(preL + 1, preL + num_left, inL, k - 1);
	root->rchild = create(preL + num_left + 1, preR, k + 1, inR);
	return root;
}

bool first = true;
void PostOrder(node* root) {
	if (root == nullptr) return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	if (first) first = false;
	else printf(" ");
	printf("%d", root->data);
}
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	string info;
	stack<int> st;
	for (int i = 0; i < 2 * n; ++i) {
		getline(cin, info);
		if (info.substr(0, 4) == "Push") {
			int num = stoi(info.substr(5));
			pre.emplace_back(num);
			st.emplace(num);
		} else {
			in.emplace_back(st.top());
			st.pop();
		}
	}
	PostOrder(create(0, n - 1, 0, n - 1));
	return 0;
}
