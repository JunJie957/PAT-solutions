#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
	 �����ʽ��

		 ������ -111,111
		 ������ -1,999,200

		 ������ 111,111
		 ������ 1,222,333
*/

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	string res = to_string(a + b);

	int len = res.size();
	for (int i = 0; i < len; ++i)
	{
		printf("%c", res[i]);
		if (res[i] == '-') continue;
		if ((i + 1) % 3 == len % 3 && i != len - 1) printf(",");
	}
	return 0; 
}
