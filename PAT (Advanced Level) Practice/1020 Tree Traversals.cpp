#include <iostream>
#include <queue>
using namespace std;
// 树结点
struct node {
    int data;
    node* lchild;
    node* rchild;
    node(int value) :data(value), lchild(nullptr), rchild(nullptr) {};
};
// 中序遍历序列 + 后序遍历序列
vector<int> in(30), post(30);
// 还原二叉树
node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR) return nullptr;
    node* Node = new node(post[postR]);
    int k, left_num = 0;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == Node->data) {
            left_num = k - inL;
            break;
        }
    }
    Node->lchild = create(postL, postL + left_num - 1, inL, k - 1);
    Node->rchild = create(postL + left_num, postR - 1, k + 1, inR);
    return Node;
}
// 层序遍历
void LayerOrder(node* root) {
    bool first = true;
    queue<node*> q;
    q.emplace(root);
    while (!q.empty()) {
        node* cur = q.front();
        q.pop();
        first ? first = false : printf(" ");
        printf("%d", cur->data);
        if (cur->lchild != nullptr) q.emplace(cur->lchild);
        if (cur->rchild != nullptr) q.emplace(cur->rchild);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)  scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i)  scanf("%d", &in[i]);
    LayerOrder(create(0, n - 1, 0, n - 1)); // 还原二叉树 + 层序遍历
    return 0;
}
