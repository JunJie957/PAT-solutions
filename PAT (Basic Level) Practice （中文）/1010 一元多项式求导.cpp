/*
	题目描述： 
	
		1010 一元多项式求导 (25分)

		设计函数求一元多项式的导数。（注：x^n（n为整数）的一阶导数为nx^n?1。）

		输入格式:
		以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

		输出格式:
		以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

		输入样例:
		3 4 -5 2 6 1 -2 0
    
		输出样例:
		12 3 -10 1 6 0
*/

/*
	题目分析：
		
		(1) 题目求解思路就是输入一对数字，计算，输出，直到文件结尾

		(2) 注意如果输入为空的话，则输出"0 0"

		(3) 注意最后一次输出不要带有空格
*/

/*
	代码实现
*/
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
