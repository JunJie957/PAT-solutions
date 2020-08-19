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

// ����һ�ö���������
void insert(node*& root, int data) {
	if (root == nullptr) {
		root = new node;
		root->data = data;
		root->left = root->right = nullptr;
		return;
	}

	if (data < root->data) {
		insert(root->left, data);
	}
	else {
		insert(root->right, data);
	}
}

// �������
void preOrder(node* root, vector<int>& v) {
	if (root == nullptr)return;
	v.push_back(root->data);
	preOrder(root->left, v);
	preOrder(root->right, v);
}

// ���������
void preOrderMirror(node* root, vector<int>& v) {
	if (root == nullptr)return;
	v.push_back(root->data);
	preOrderMirror(root->right, v);
	preOrderMirror(root->left, v);
}

// �������
void postOrder(node* root, vector<int>& v) {
	if (root == nullptr)return;
	postOrder(root->left, v);
	postOrder(root->right, v);
	v.push_back(root->data);
}

// ���������
void postOrderMirror(node* root, vector<int>& v) {
	if (root == nullptr)return;
	postOrderMirror(root->right, v);
	postOrderMirror(root->left, v);
	v.push_back(root->data);
}

/*
	����˼·��

	(1) ���ݳ�ʼ���ݣ��Ȼ�ԭһ�Ŷ���������
	(2) ���ݻ�ԭ��Ķ������������������򡢺��򡢾������򡢾���������
	(3) �Ƚ�����Ķ��кͽ����Ķ����Ƿ���ͬ�������ͬ�ͱ�ʾ����������Ǿ�������
	(4) �����ͬ���������Ӧ�ĺ������������

	(5) Ӧ���������գ��������Ľڵ㣨��ԭ�����������������򡢺���������� 
*/

// origin�� �����������ݳ�ʼ����Ķ���������
// pre,postΪ���򡢺���preM,postMΪ���������򡢺���
vector<int> origin, pre, post, preM, postM;
int main()
{
	int n, data;
	node* root = nullptr;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);	// ��ԭһ�ö���������
	}

	// ���������
	preOrder(root, pre);
	// �����������
	preOrderMirror(root, preM);
	// ��������
	postOrder(root, post);
	// ����������
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
