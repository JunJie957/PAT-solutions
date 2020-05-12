#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

struct people
{
	char name[5];
	int year;
	int month;
	int day;
};

int main()
{
	int n, count = 0;
	cin >> n;

	people tmp;
	vector<people> v;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);
		
		if (tmp.year < 1814 || (tmp.year == 1814 && tmp.month < 9) || (tmp.year == 1814 && tmp.month == 9 && tmp.day < 6))
			continue;
		
		if (tmp.year > 2014 || (tmp.year == 2014 && tmp.month > 9) || (tmp.year == 2014 && tmp.month == 9 && tmp.day > 6))
			continue;

		++count;
		v.push_back(tmp);
	}

	cout << count;
	if (count > 0)
	{
		tmp = v[0];
		for (int i = 1; i < v.size(); ++i)
		{
			if (v[i].year < tmp.year || (v[i].year == tmp.year && v[i].month < tmp.month) || (v[i].year == tmp.year && v[i].month == tmp.month && v[i].day < tmp.day))
				tmp = v[i];
		}
		cout << " " << tmp.name;

		tmp = v[0];
		for (int i = 1; i < v.size(); ++i)
		{
			if (v[i].year > tmp.year || (v[i].year == tmp.year && v[i].month > tmp.month) || (v[i].year == tmp.year && v[i].month == tmp.month && v[i].day > tmp.day))
				tmp = v[i];
		}
		cout << " " << tmp.name;
	}

	return 0;
}
