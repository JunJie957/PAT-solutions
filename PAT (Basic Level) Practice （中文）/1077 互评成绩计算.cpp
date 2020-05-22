#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	int teacher, tmp;
	vector<int> stu;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &tmp);
			if (j == 0)  teacher = tmp;
			else if (tmp >= 0 && tmp <= m) stu.push_back(tmp);
		}
		sort(stu.begin(), stu.end());
		
		double sum = 0;
		for (int i = 1; i < stu.size() - 1; ++i)
			sum += stu[i];
		
		sum = sum / (stu.size() - 2);
		sum += teacher;
		printf("%.lf\n", round(sum / 2));

		stu.clear();
	}
	return 0;
}
