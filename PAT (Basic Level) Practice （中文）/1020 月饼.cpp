#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct moonpie
{
	double stock;
	double total_price;
	double unit_price;
};

bool compare_price(const moonpie& a, const moonpie& b)
{
	return a.unit_price > b.unit_price;
}

int main()
{
	int category;
	cin >> category;

	int need;
	cin >> need;

	vector<moonpie> v(category);
	for (int i = 0; i < category; ++i)
		cin >> v[i].stock;
	for (int i = 0; i < category; ++i)
		cin >> v[i].total_price;
	for (int i = 0; i < category; ++i)
		v[i].unit_price = v[i].total_price / v[i].stock;

	sort(v.begin(), v.end(), compare_price);

	double sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (need > v[i].stock)
		{
			sum += v[i].total_price;
			need -= v[i].stock;
		}
		else
		{
			sum += (v[i].unit_price * need);
			break;
		}
	}

	printf("%.2f", sum);

	return 0;
}
