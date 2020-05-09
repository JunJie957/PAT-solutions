#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int a, b, c;
	for (int i = 0; i < T; ++i)
	{
		cin >> a >> b >> c;
		if (b > c - a)
			cout << "Case #" << i + 1 << ": true" << endl;
		else
			cout << "Case #" << i + 1 << ": false" << endl;
	}
	return 0;
}
