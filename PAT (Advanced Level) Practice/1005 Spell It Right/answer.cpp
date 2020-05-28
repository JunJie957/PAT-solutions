#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char number[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	string str;
	cin >> str;

	int len = str.length();
	long long res = 0;
	for (int i = 0; i < len; ++i)
		res += str[i] - '0';

	str = to_string(res);
	len = str.length();

	printf("%s", number[str[0] - '0']);
	for (int i = 1; i < len; ++i)
	{
		printf(" %s", number[str[i] - '0']);
	}
	return 0; 
}
