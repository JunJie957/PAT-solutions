#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

vector<int> inorder;		// �������
vector<int> postorder;		// �������
vector<int> binaryTree;		// ��ԭ��Ķ�����

node* create(int postL, int postR, int inL, int inR)
{
	if (postL > postR) return nullptr;

	node* root = new node;
	root->data = postorder[postR];

	int k;
	for (k = inL; k <= inR; ++k)
	{
		if (inorder[k] == postorder[postR])
			break; // ����������У��ҵ����ڵ�
	}

	int numLeft = k - inL;	// ���ҵ�ƫ����

	// ������
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);

	// ������
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);

	return root;
}

// �������
void LayerOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	bool flag = true;
	while (!q.empty())
	{
		node* root = q.front();
		
		// ��һ�����ʱ��������ո�
		if (flag) flag = false;
		else printf(" ");
		
		printf("%d", root->data);

		q.pop();

		if (root->lchild != nullptr) q.push(root->lchild);
		if (root->rchild != nullptr) q.push(root->rchild);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	inorder.resize(n);
	postorder.resize(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &inorder[i]);
	}

	node* root = create(0, n - 1, 0, n - 1);
	LayerOrder(root);
	
	return 0;
}
