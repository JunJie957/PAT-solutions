#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int t; 
	scanf("%d", &t);

	long long a, b, c;
	for (int i = 0; i < t; ++i) 
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if (b > c - a) 
		{
			printf("Case #%d: true\n", i + 1);
		}
		else 
		{
			printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}

