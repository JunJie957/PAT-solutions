#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100010;
int count_p[MAXN] = { 0 };

int main()
{
	string str;
	cin >> str;

	int size = str.length();
	for (int i = 0; i < size; ++i)
	{
		if (i > 0)
		{
			count_p[i] = count_p[i - 1];
		}

		if (str[i] == 'P')
		{
			count_p[i]++;
		}
	}

	int ans = 0; 
	int right = 0;
	for (int j = size - 1; j >= 0; --j)
	{
		if (str[j] == 'T')
		{
			right++;
		}
		else if(str[j] == 'A' && right > 0 && count_p[j] > 0)
		{
			ans += count_p[j] * right;
			if (ans >= 1000000007)
			{
				ans %= 1000000007;
			}
		}
	}
	printf("%d", ans);
	return 0;
}