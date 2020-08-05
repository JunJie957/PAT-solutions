#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	long int n;
	scanf("%ld", &n);
	printf("%ld=", n);

	// n = 1，特殊处理，因为素数查找是从 2 开始的
	if (n == 1)
	{
		printf("1");
		return 0;
	}

	// find prime
	vector<bool> notPrime(n, 0);	// 默认[0,n]全为素数
	vector<int> prime;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (notPrime[i] == false)
		{
			prime.push_back(i);
			for (int j = i + i; j <= sqrt(n); j += i)
			{
				notPrime[j] = true; // 将此素数的所有倍数标记为非素数
			}
		}
	}

	// found factor
	vector<pair<int, int>> factor;
	for (int i = 0; i < prime.size(); ++i)
	{
		if (n % prime[i] == 0)
		{
			factor.push_back(make_pair(prime[i], 1));
			n /= prime[i];
			
			while (n % prime[i] == 0)
			{
				factor[factor.size() - 1].second++;
				n /= prime[i];
			}
		}
	}

	// 如果n还未被除尽，则说明有一个质因子在[sqrt(n),n]之间，将其包含在质因子数组中
	if (n != 1) factor.push_back(make_pair(n, 1));

	// 执行打印
	int size = factor.size();
	for (int i = 0; i < size; ++i)
	{
		if (i != 0) printf("*");
		printf("%d", factor[i].first);
		if (factor[i].second != 1) printf("^%d", factor[i].second);
	}
	return 0;
}
