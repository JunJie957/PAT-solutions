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

	// n = 1�����⴦����Ϊ���������Ǵ� 2 ��ʼ��
	if (n == 1)
	{
		printf("1");
		return 0;
	}

	// find prime
	vector<bool> notPrime(n, 0);	// Ĭ��[0,n]ȫΪ����
	vector<int> prime;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (notPrime[i] == false)
		{
			prime.push_back(i);
			for (int j = i + i; j <= sqrt(n); j += i)
			{
				notPrime[j] = true; // �������������б������Ϊ������
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

	// ���n��δ����������˵����һ����������[sqrt(n),n]֮�䣬���������������������
	if (n != 1) factor.push_back(make_pair(n, 1));

	// ִ�д�ӡ
	int size = factor.size();
	for (int i = 0; i < size; ++i)
	{
		if (i != 0) printf("*");
		printf("%d", factor[i].first);
		if (factor[i].second != 1) printf("^%d", factor[i].second);
	}
	return 0;
}
