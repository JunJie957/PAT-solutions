#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string champion, rookie, name;
	int max = -1, min = 200, x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> x >> y;
		int distance = sqrt(x * x + y * y);

		if (distance < min)
		{
			champion = name;
			min = distance;
		}

		if (distance > max)
		{
			rookie = name;
			max = distance;
		}
	}
	cout << champion << " " << rookie;
	return 0;
}
