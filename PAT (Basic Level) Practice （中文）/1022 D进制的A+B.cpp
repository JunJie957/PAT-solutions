#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int a,b,d;

	cin >> a >> b >> d;
	a += b;
	
	if (a == 0)
	{
		cout << "0"; // �������ĺ�Ϊ0����ֱ�����0
		return 0;
	}

	stack<int> s;
	while (a >= d)
	{
		s.push(a % d);
		a /= d;
	}
	if (a != 0) s.push(a);
	
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}
