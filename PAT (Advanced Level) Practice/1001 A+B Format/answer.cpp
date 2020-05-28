#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
	 输出样式：

		 负数： -111,111
		 负数： -1,999,200

		 正数： 111,111
		 正数： 1,222,333
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
