#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// scanf()和printf()的运行效率比cin和cout高一些：通过提交通过的时间记录判断 

int main()
{
	int number[10] = { 0 };
	bool flag = true;
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &number[i]);
		if (flag && number[i] > 0 && i != 0)
		{
			printf("%d", i);	// 输出首位不为零的数字
			--number[i];
			flag = false;
		}
	}

	// 接下来按从小到大的顺序输出其他所有的数字
	for (int i = 0; i < 10; ++i)
	{
		while (number[i] > 0)
		{
			printf("%d", i);
			--number[i];
		}
	}
	return 0;
}
