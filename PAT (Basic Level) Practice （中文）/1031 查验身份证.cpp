#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int arr[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char m[] =  { '1','0','X','9','8','7','6','5','4','3','2'};

	int n;
	cin >> n;
	
	string str;
	bool all_passed = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;

		// 处理身份证前17位
		bool str_flag = true;
		int sum = 0;		// 记得每次计算完毕，sum要清零
		for (int j = 0; j < str.size() - 1; ++j)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				int tmp = str[j] - '0';
				sum += tmp * arr[j];
			}
			else
			{
				cout << str << endl;
				str_flag = false;
				all_passed = false;
				break;
			}
		}

		// 处理最后一位
		if (str_flag)
		{
			sum %= 11;
			if (m[sum] != str[17])
			{
				all_passed = false;
				cout << str << endl;
			}
		}
	}
	if (all_passed) cout << "All passed" << endl;

	return 0;
}
