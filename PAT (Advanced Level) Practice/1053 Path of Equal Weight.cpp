#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100;

struct node
{
	int weight;			// ������
	vector<int> child;	// ָ����
}Node[MAXN];

bool cmp(int a, int b)
{
	// �����������Ӵ�С����
	return Node[a].weight > Node[b].weight;
}

int n, m, s;	// ������������������ĺ�
int path[MAXN];	// �洢��ʱ��·��

// ��ǰ���ʽڵ�Ϊindex��numNodeΪ��ǰ·��path�ϵĽڵ����
// sumΪ��ǰ�Ľڵ��Ȩ��
void DFS(int index, int numNode, int sum)
{
	if (sum > s) return;
	if (sum == s)
	{
		// �����ʱ��û�е���Ҷ�ӽڵ㣬��ֱ�ӷ���
		if (Node[index].child.size() != 0) return;
		
		for (int i = 0; i < numNode; i++)
		{
			printf("%d", Node[path[i]].weight);
			if (i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}

	// �������е��ӽڵ�
	for (int i = 0; i < Node[index].child.size(); ++i)
	{
		int child = Node[index].child[i];	// �ڵ�indx�ĵ�i���ӽڵ���
		path[numNode] = child; // ��¼��ǰ·��
		DFS(child, numNode + 1, sum + Node[child].weight); // �ݹ������һ��
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &Node[i].weight);
	}

	int id, k, child;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}

		// ����:�����������Ӵ�С����
		sort(Node[id].child.begin(), Node[id].child.end(), cmp); 
	}

	path[0] = 0;
	DFS(0, 1, Node[0].weight); // DFS���
	return 0;
}
