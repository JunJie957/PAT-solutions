#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	char c;
	int lines;
	cin >> n >> c;

	// ע�⣬��Ŀ˵��������ȡ����Ӧ��������ȡ��
	lines = ceil((double)n / 2);
	for (int i = 0; i < lines; ++i)
	{
		if (i == 0 || i == lines - 1)
		{
			for (int j = 0; j < n; ++j) printf("%c", c);
			printf("\n");
		}
		else
		{
			for (int j = 0; j < n; ++j)
			{ 
				if (j == 0 || j == n - 1) 	printf("%c", c);
				else printf(" ");
			}
			printf("\n");
			
		}
	}

	return 0;
}
