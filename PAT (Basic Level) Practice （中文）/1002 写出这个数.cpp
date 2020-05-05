/*
	题目解析：

		1002 写出这个数 (20分)

		读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

		输入格式：
		每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100。

		输出格式：
		在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，
		但一行中最后一个拼音数字后没有空格。

		输入样例：
		1234567890987654321123456789

		输出样例：
		yi san wu
*/


/*
	题目分析：

		(1) 创建一个用于数字和拼音转换的数组：spell_str[10]
		(2) 先遍历输入的字符串，然后将每一个字符转换为数字，并叠加
		(3) 为了实现输出数字的拼音形式，再次将sum转换为字符串，遍历，输出对应的数字的拼音形式
*/

/*
	代码实现
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// 字符数组，用于数字和拼音的转换
string spell[10] = {
		"ling","yi", "er", "san",
		"si","wu","liu","qi","ba",
		"jiu"
};

int main()
{
	// 以字符串的形式输入
	string number;
	cin >> number;

	// 计算每一位的总和
	int sum = 0;
	for (unsigned int i = 0; i < number.size(); ++i)
		sum += (number[i] - '0');

	// 将sum的每一位数字以拼音的形式输出
	string tmp = to_string(sum);
	for (unsigned int i = 0; i < tmp.size() - 1; ++i)
		cout << spell[tmp[i] - '0'] << " ";

	// 最后一位的输出不输出空格
	cout << spell[tmp[tmp.size() - 1] - '0'];

	return EXIT_SUCCESS;
}
