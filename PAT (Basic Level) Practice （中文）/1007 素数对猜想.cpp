/*
	题目描述：

		1007 素数对猜想 (20分)
		
		“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

		现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

		输入格式:
		输入在一行给出正整数N。

		输出格式:
		在一行中输出不超过N的满足猜想的素数对的个数。

		输入样例:
		20

		输出样例:
		4
*/

/*
	题目分析：
		
		(1) 遍历从5-n的所有数字，判断i-2和i是否都是素数，如果是，则计数+1

		(2) 素数判断，只需判断当前数字值的一半即可
*/

/*
	代码实现
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int val)
{
	for (int i = 2; i * i <= val; ++i)
		if (val % i == 0) return false;
	return true;
}

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for (int i = 5; i <= n; ++i)
		if (isPrime(i - 2) && isPrime(i)) ++count;
	
	cout << count;
	return 0;
}
