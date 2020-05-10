#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	// 符号位
	if (s[0] == '-') cout << "-";
	
	string integer;	// 整数部分
	string index;	// 指数部分
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] != 'E')
			integer += s[i];
		else
		{
			index = s.substr(i + 1);
			break;
		}
	}
	
	int index_i = atof(index.c_str());
	if (index_i > 0)
	{
		int loc = integer.size() - 2;		// 小数点和最后一位数之间的距离
		integer.erase(integer.begin() + 1); // 删除小数点

		if (loc > index_i)
		{
			// 将小数点后移 index_i 位
			integer.insert(integer.begin() + index_i + 1, '.');
		}
		else if(loc < index_i)
		{
			// 在数字末尾添加对应数量的零
			for (int i = 0; i < index_i - loc; ++i)
				integer += '0';
		}
	}
	else if(index_i < 0)
	{
		integer.erase(integer.begin() + 1); // 删除小数点
	
		// 在整数部分前面填零
		for (int i = 0; i < abs(index_i) - 1; ++i)
			integer.insert(integer.begin(), '0');
		
		// 添加整数部分和小数点
		integer.insert(integer.begin(), '.');
		integer.insert(integer.begin(), '0');
	}

	cout << integer << endl;
	return 0;
}
