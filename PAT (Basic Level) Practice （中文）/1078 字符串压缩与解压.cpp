#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c;
	scanf("%c", &c);
	getchar();

	string tmp;
	getline(cin,tmp);
	int len = tmp.size();
	if (c == 'C')
	{
		if (!tmp.empty()) c = tmp[0];
		int count = 1;
		for (int i = 1; i < len; ++i)
		{
			if (c != tmp[i])
			{
				if (count != 1) printf("%d%c", count, c);
				else printf("%c", c);

				c = tmp[i];
				count = 1;
			}
			else
			{
				count++;
			}

			if (i == len - 1)
			{
				if (count != 1) printf("%d%c", count, c);
				else printf("%c", c);
			}
		}
	}
	else if (c == 'D')
	{
		string number;
		for (int i = 0; i < len; ++i)
		{
			if (tmp[i] >= '0' && tmp[i] <= '9')
			{
				number += tmp[i];
			}
			else
			{
				printf("%c", tmp[i]);
				for (int j = 1; j < atoi(number.c_str()); ++j)
					printf("%c", tmp[i]);
				number.clear();
			}
		}
	}

	return 0;
}
