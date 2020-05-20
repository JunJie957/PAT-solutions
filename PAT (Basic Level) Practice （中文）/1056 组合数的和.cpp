#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		v.push_back(temp);
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == i) continue;
			sum = sum + v[i] * 10 + v[j];
		}
	}
	cout << sum;
	return 0;
}
