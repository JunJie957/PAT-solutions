#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

// 在二叉搜索树中插入新的节点
void insert(node*& root, int data) {
	if (root == nullptr) {
		root = new node;
		root->data = data;
		root->left = root->right = nullptr;
		return;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}

// 使用数组创建一颗二叉搜索树
node* create(vector<int> v) {
	node* root = nullptr;
	for (int i = 0; i < v.size(); ++i) {
		insert(root, v[i]);
	}
	return root;
}

// 先序遍历
void preOrder(node* root,vector<int>& v) {
	if (root == nullptr) return;
	v.push_back(root->data);
	preOrder(root->left, v);
	preOrder(root->right, v);
}

// 后序遍历
void postOrder(node* root, vector<int>& v) {
	if (root == nullptr) return;
	postOrder(root->left, v);
	postOrder(root->right, v);
	v.push_back(root->data);
}

// 先序镜像遍历
void preOrderMirror(node* root, vector<int>& v) {
	if (root == nullptr) return;
	v.push_back(root->data);
	preOrderMirror(root->right, v);
	preOrderMirror(root->left, v);
}

// 后序镜像遍历
void postOrderMirror(node* root, vector<int>& v) {
	if (root == nullptr) return;
	postOrderMirror(root->right, v);
	postOrderMirror(root->left, v);
	v.push_back(root->data);
}

/*
	解题思路：

	(1) 根据初始数据，先还原一颗二叉搜索树
	(2) 根据还原后的二叉搜索树，建立先序、后序、镜像先序、镜像后序队列
	(3) 比较输入的队列和建立的队列是否相同，如果相同就表示是先序或者是镜像先序
	(4) 如果相同，则输出对应的后序或镜像后序队列

	(5) 应该熟练掌握，插入树的节点（还原二叉搜索树）、先序、后序遍历操作 
*/

// origin： 根据输入数据初始化后的二叉排序树
// pre,post为先序、后序；preM,postM为镜像树先序、后序
vector<int> origin, pre, post, preM, postM;
int main()
{
	int n, data;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data);
		origin.push_back(data);
	}

	// 根据输入序列还原二叉搜索树
	node* root = create(origin);

	// 求先序遍历
	preOrder(root, pre);
	// 求先序镜像遍历
	preOrderMirror(root, preM);
	// 求后序遍历
	postOrder(root, post);
	// 求后序镜像遍历
	postOrderMirror(root, postM);

	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			if (i < n - 1) printf("%d ", post[i]);
			else printf("%d", post[i]);
		}
	}
	else if (origin == preM) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			if (i < n - 1) printf("%d ", postM[i]);
			else printf("%d", postM[i]);
		}
	}
	else {
		printf("NO");
	}
	return 0;
}
