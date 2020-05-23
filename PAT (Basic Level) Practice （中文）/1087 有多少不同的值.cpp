#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	set<int> s;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(floor(i / 2) + floor(i / 3) + floor(i / 5));
	}
	printf("%d", s.size());

	return 0;
}
