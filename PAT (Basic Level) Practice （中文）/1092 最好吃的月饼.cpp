#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int temp;
	vector<int> v(n, 0);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &temp);
			v[j - 1] += temp;
		}
	}

	int max = -1;
	vector<int> loc;	 // 存储位置坐标信息
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > max)
		{
			loc.clear();
			max = v[i];
			loc.push_back(i + 1);
		}
		else if (v[i] == max) loc.push_back(i + 1);
	}

	printf("%d\n", max);
	sort(loc.begin(), loc.end());
	for (int i = 0; i < loc.size(); ++i)
	{
		if (i != 0) printf(" ");
		printf("%d", loc[i]);
	}

	return 0;
}
