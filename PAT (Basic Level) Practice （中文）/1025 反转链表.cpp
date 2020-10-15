#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> datas(100001); // 存储数据值，下标为其地址
vector<int> nexts(100001); // 存储下一个节点值
vector<int> lists(100001); // 用于将地址连续存储起来，以便后续反转

int main()
{
    int head, n, k, temp;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        scanf("%d%d", &datas[temp], &nexts[temp]);
    }

    int loc = 0;    // 可连接的节点总数有可能不是n个，此处使用loc记录所有连接的节点数量
    while (head != -1) {
        lists[loc++] = head;
        head = nexts[head];
    }

    for (int i = 0; i < loc - loc % k; i += k) {
        reverse(lists.begin() + i, lists.begin() + i + k);
    }

    for (int i = 0; i < loc - 1; ++i) {
        printf("%05d %d %05d\n", lists[i], datas[lists[i]], lists[i + 1]);
    }

    printf("%05d %d -1", lists[loc - 1], datas[lists[loc - 1]]);
    return 0;
}
