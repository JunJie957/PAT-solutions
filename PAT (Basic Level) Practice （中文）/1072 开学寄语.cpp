#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	string tmp;
	unordered_set<string> s;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		s.insert(tmp);
	}

	string name;
	string goods_num;
	int count, stu_count = 0, goods_count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> count;
		bool find = false;
		for (int j = 0; j < count; ++j)
		{
			cin >> goods_num;
			if (s.find(goods_num) != s.end())
			{
				if (!find)
				{
					find = true;
					printf("%s:", name.c_str());
				}
				printf(" %s",goods_num.c_str());
				goods_count++;
			}
		}
		if (find)
		{
			printf("\n");
			stu_count++;
		}
	}
	printf("%d %d", stu_count, goods_count);
	return 0;
}
