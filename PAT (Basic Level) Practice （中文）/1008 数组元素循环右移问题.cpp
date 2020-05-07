/*
	题目描述： 
	
		1008 数组元素循环右移问题 (20分)

		输入格式:
		每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

		输出格式:
		在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

		输入样例:
		6 2
		1 2 3 4 5 6

		输出样例:
		5 6 1 2 3 4
*/

/*
	题目分析：
		
		题目只是按要求输出，完全可以不做移动操作，在对应的位置输出数字即可
*/

/*
	代码实现
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int n, m;
	int arr[101] = { 0 };

	cin >> n >> m;

	// 为保证m不大于n，对m进行取余操作
	m %= n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	for (int i = n - m; i < n; ++i)
		if (n - m == 0 && i == n - 1) cout << arr[i];
		else cout << arr[i] << " ";

	for (int i = 0; i < n - m; ++i)
		if (i == n - m - 1) cout << arr[i];
		else cout << arr[i] << " ";
			
	return 0;
}
