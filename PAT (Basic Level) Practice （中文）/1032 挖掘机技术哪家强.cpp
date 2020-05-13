#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int school, score;
	vector<int> v(100001, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> school >> score;
		v[school] += score;
	}

	int i = 1, sum = 0, loc = -1;
	for (; i < v.size(); ++i)
	{
		if (v[i] > sum)
		{
			sum = v[i];
			loc = i;
		}
	}

	cout << loc << " " << sum;

	return 0;
}
