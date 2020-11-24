// 方法1： DFS 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maxDepth = -1;
vector<int> book(100, 0);
unordered_map<int, vector<int>> um;

void dfs(int index, int depth) {
    if (um.find(index) == um.end()) {
        ++book[depth];
        maxDepth = max(maxDepth, depth);
    } else {
        int size = um[index].size();
        for (int i = 0; i < size; ++i) {
            dfs(um[index][i], depth + 1);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int id, k, children;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &children);
            um[id].emplace_back(children);
        }
    }

    dfs(1, 0);

    printf("%d", book[0]);
    for (int i = 1; i <= maxDepth; ++i) {
        printf(" %d", book[i]);
    }
    return 0;
}

// 方法2: tree + layer traversal / BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	vector<node*> child;
	node(int val) :data(val) {};
};

void DFS(node* root) {
	bool flag = true;
	queue<vector<node*>> q;
	q.push({ root });
	while (!q.empty()) {
		vector<node*> cur = q.front();
		q.pop();
		int cnt = 0;
		vector<node*> next_layer;
		for (int i = 0; i < cur.size(); ++i) {
			if (cur[i]->child.empty()) ++cnt;
			for (int j = 0; j < cur[i]->child.size(); ++j) {
				next_layer.emplace_back(cur[i]->child[j]);
			}
		}
		if (!next_layer.empty()) {
			q.emplace(next_layer);
		}
		if (flag) flag = false;
		else printf(" ");
		printf("%d", cnt);
	}
}
int main() {
	int n, m, k, num, child;
	scanf("%d%d", &n, &m);
	vector<node*> tree(n + 1);
	for (int i = 0; i <= n; ++i) {
		tree[i] = new node(i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &num, &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &child);
			tree[num]->child.emplace_back(tree[child]);
		}
	}
	DFS(tree[1]);
	return 0;
}
