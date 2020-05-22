#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);

	sort(v.begin(), v.end());
	
	int res = v[0];
	for (int i = 1; i < n; ++i)
		res = (res + v[i]) / 2;
	
	cout << res;

	return 0;
}
