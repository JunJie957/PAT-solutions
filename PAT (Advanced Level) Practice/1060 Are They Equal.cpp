 #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string choopingString(string s, int& e, int n)
{
	string res = "0.";	

	// 去掉前导零，类似 000000.001
	while (s.length() > 0 && s[0] == '0')
		s.erase(s.begin());

	// 碰到小数点后，继续进行去除零的操作
	if (s.length() > 0 && s[0] == '.')
	{
		s.erase(s.begin()); // 去掉小数点
		while (s.length() > 0 && s[0] == '0')
		{
			s.erase(s.begin()); // 去掉小数后面的零 类似 0.000001
			--e;
		}

		// 如果去掉小数点后的零，字符串长度为零，则整个字符串为零 类似 0.0000000
		if (s.length() == 0) e = 0;
	}
	else 
	{// 如果去除前导零后，没有遇到小数点，则统计指数
		int len = s.length();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '.')
			{
				s.erase(s.begin() + i);	// 遇到小数点，停止统计，并删除小数点
				break;
			}
			else ++e;
		}
	}

	int num = 0, loc = 0, len = s.length();
	while (num++ < n)
	{
		if (loc < len)  res += s[loc++];
		else  res += '0';	// 补零
	}
	return res;
}

int main()
{
	// 输入
	int n;
	string a, b;
	cin >> n >> a >> b;

	// 指数
	int e1 = 0, e2 = 0; 
	
	// 计算指数及处理后的字符串
	string r1 = choopingString(a, e1, n);
	string r2 = choopingString(b, e2, n);
	
	// 打印处理
	if (r1.compare(r2) == 0 && e1 == e1)
		printf("YES %s*10^%d", r1.c_str(), e1);
	else
		printf("NO %s*10^%d %s*10^%d", r1.c_str(), e1, r2.c_str(), e2);
	
	return 0;
}
