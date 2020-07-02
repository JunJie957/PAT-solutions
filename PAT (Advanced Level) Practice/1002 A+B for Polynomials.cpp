#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k, n;
	float a, b;
	vector<float> v(1001, 0);
	
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %f", &n, &a);
		v[n] += a;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %f", &n, &b);
		v[n] += b;
	}

	int count = 0;
	for (int i = 1000; i >= 0; --i)
	{
		if (v[i] != 0) ++count;
	}

	printf("%d", count);
	for (int i = 1000; i >= 0; --i)
	{
		if (v[i] != 0) printf(" %d %.1f", i, v[i]);
	}
	return 0; 
}
