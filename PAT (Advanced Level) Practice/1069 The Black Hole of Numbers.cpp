#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string n;
	cin >> n;

	while (n.length() < 4)
	{
		n.append("0");	// 不足位补零
	}

	sort(n.begin(), n.end(), greater<int>());
	int r1 = atoi(n.c_str());

	sort(n.begin(), n.end());
	int r2 = atoi(n.c_str());
	int ans = r1 - r2;
	printf("%04d - %04d = %04d\n", r1, r2, ans);

	// 验证是否是相同位的数字
	while (ans != 6174 && ans != 0)
	{
		n = std::to_string(ans);
		while (n.length() < 4)
		{
			n.append("0");	// 不足位补零
		}

		sort(n.begin(), n.end(), greater<int>());
		r1 = atoi(n.c_str());

		sort(n.begin(), n.end());
		r2 = atoi(n.c_str());

		ans = r1 - r2;
		printf("%04d - %04d = %04d\n", r1, r2, ans);
	}
	return 0;
}
