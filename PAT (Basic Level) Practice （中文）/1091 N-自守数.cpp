#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int m;
	scanf("%d", &m);

	int value;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &value);
		bool flag = false;
		for (int j = 1; j < 10; ++j)
		{
			int len = to_string(value).size();
			string multi = to_string(j * value * value);
			int tail = atoi(multi.substr(multi.size() - len).c_str());
			if (tail == value)
			{
				flag = true;
				printf("%d %s\n", j, multi.c_str());
				break;
			}
		}
		if (!flag) printf("No\n");
	}
	return 0;
}
