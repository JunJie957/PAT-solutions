#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100;

struct node
{
	int weight;			// 数据域
	vector<int> child;	// 指针域
}Node[MAXN];

bool cmp(int a, int b)
{
	// 按结点数据域从大到小排序
	return Node[a].weight > Node[b].weight;
}

int n, m, s;	// 结点数，边数，给定的和
int path[MAXN];	// 存储临时的路径

// 当前访问节点为index，numNode为当前路径path上的节点个数
// sum为当前的节点点权和
void DFS(int index, int numNode, int sum)
{
	if (sum > s) return;
	if (sum == s)
	{
		// 如果此时还没有到达叶子节点，则直接返回
		if (Node[index].child.size() != 0) return;
		
		for (int i = 0; i < numNode; i++)
		{
			printf("%d", Node[path[i]].weight);
			if (i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}

	// 遍历所有的子节点
	for (int i = 0; i < Node[index].child.size(); ++i)
	{
		int child = Node[index].child[i];	// 节点indx的第i个子节点编号
		path[numNode] = child; // 记录当前路径
		DFS(child, numNode + 1, sum + Node[child].weight); // 递归进入下一层
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

		// 排序:按结点数据域从大到小排序
		sort(Node[id].child.begin(), Node[id].child.end(), cmp); 
	}

	path[0] = 0;
	DFS(0, 1, Node[0].weight); // DFS求解
	return 0;
}
