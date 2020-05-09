#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i, j;
	bool flag = false;

	while (scanf("%d%d", &i, &j) != EOF)
	{
		if (j != 0)
		{
			if (flag == false)
			{
				cout << i * j << " " << j - 1;
				flag = true;
			}
			else
			{
				cout << " " << i * j << " " << j - 1;
			}
		}
	}
	if (flag == false)  cout << "0 0";
	return 0;
}
