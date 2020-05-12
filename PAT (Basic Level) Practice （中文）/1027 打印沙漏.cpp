#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int n;
	char c;

	cin >> n >> c;

	
	n -= 1;
	int line = 1;
	int base = 3;

	// 计算能用掉多少个符号
	while (n >= base * 2)
	{
		n -= base * 2;
		base += 2;	
		line += 2;	// 计算行数
	}

	int space = 0;
	int start = line;
	for (int i = 1; i <= line; ++i)
	{
		// 先输出空格
		for (int k = 0; k < space; ++k)  cout << " ";
		
		// 输出符号
		for (int j = start; j >= 1; --j) cout << c;
		
		// 换行
		cout << endl;

		// 每打印一行就要更新空格和需要打印的符号的数量
		if (i <= line / 2)
		{
			start -= 2;
			space++;
		}
		else
		{
			start += 2;
			space--;
		}
	}
	// 打印剩余未使用符号的数量
	cout << n << endl;	
	return 0;
}
