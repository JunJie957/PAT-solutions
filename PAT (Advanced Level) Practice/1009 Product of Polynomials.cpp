#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<float> v(2001, 0);
int main()
{
	int k;
	scanf("%d", &k);
	
	int a;
	float b;
	unordered_map<int, float> um;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %f", &a, &b);
		um.insert(pair<int, float>(a, b));
	}

	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %f", &a, &b);
		for (auto iter = um.begin(); iter != um.end(); ++iter)
		{
			int loc = iter->first + a;
			float sum = iter->second * b;
			v[loc] += sum;
		}
	}

	int count = 0;
	for (int i = 0; i <= 2000; ++i)
		if (v[i] != 0) ++count;

	printf("%d", count);
	for (int i = 2000; i >= 0; --i)
	{
		if (v[i] == 0) continue;
		else printf(" %d %0.1f", i, v[i]);
	}

	return 0;
}
