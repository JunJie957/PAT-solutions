#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data
{
	int adr;
	int key;
	int next;
	bool check;

	Data() :check(false){};
};

const int MAXN = 100000;
vector<Data> v(MAXN);

bool cmp(const Data* d1, const Data* d2)
{
	return d1->key < d2->key;
}

int main()
{
	int n;
	int head;
	scanf("%d %d", &n, &head);

	Data tmp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &tmp.adr, &tmp.key, &tmp.next);
		tmp.check = true;
		v[tmp.adr] = tmp;
	}

	// ����̬��������Ч�Ľڵ㸴�Ƶ� v2 ��
	// ����Ҫע�Ⲣ������������Ľڵ㶼����Ч�ģ�������һ�����ܺ���
	vector<Data*> v2;
	while (head != -1)
	{
		v2.push_back(&v[head]);
		head = v[head].next;
	}

	// ����ڵ�������׵�ַ
	int size = v2.size();
	if (!size)
	{
		printf("0 -1\n");
		return 0;
	}

	// ���򣺸���key����С����
	sort(v2.begin(), v2.end(), cmp);

	// �����Ч�ڵ������ͷ���
	printf("%d %05d\n", size, v2[0]->adr);
	
	// ����ڵ���Ϣ
	for (int i = 0; i < size - 1; ++i)
	{
		printf("%05d %d %05d\n", v2[i]->adr, v2[i]->key, v2[i + 1]->adr);
	}

	// ���β���
	printf("%05d %d -1", v2[size - 1]->adr, v2[size - 1]->key);

	return 0;
}
