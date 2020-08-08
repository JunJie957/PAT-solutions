#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAXN = 100000;

// ¾²Ì¬Á´±í
struct Address
{
	char data;
	int next;
	bool mark_a;
}tmp[MAXN];

int main()
{
	int f1, f2, n;
	scanf("%d%d%d", &f1, &f2, &n);

	int adr = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &adr);
		cin >> tmp[adr].data >> tmp[adr].next;
		tmp[adr].mark_a = false;
	}

	int loc = -1;
	while (f1 != -1)
	{
		tmp[f1].mark_a = true;
		f1 = tmp[f1].next;
	}

	while (f2 != -1)
	{
		if (tmp[f2].mark_a)
		{
			loc = f2;
			break;
		}
		f2 = tmp[f2].next;
	}

	if (loc != -1)printf("%05d", loc);
	else printf("-1");

	return 0;
}
