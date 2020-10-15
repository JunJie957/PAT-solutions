#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> datas(100001); // �洢����ֵ���±�Ϊ���ַ
vector<int> nexts(100001); // �洢��һ���ڵ�ֵ
vector<int> lists(100001); // ���ڽ���ַ�����洢�������Ա������ת

int main()
{
    int head, n, k, temp;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        scanf("%d%d", &datas[temp], &nexts[temp]);
    }

    int loc = 0;    // �����ӵĽڵ������п��ܲ���n�����˴�ʹ��loc��¼�������ӵĽڵ�����
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
