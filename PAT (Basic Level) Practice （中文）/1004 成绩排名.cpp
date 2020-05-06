/*
	题目描述：

		1004 成绩排名 (20分)

		读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

		输入格式：
		每个测试输入包含 1 个测试用例，格式为

		第 1 行：正整数 n
		第 2 行：第 1 个学生的姓名 学号 成绩
		第 3 行：第 2 个学生的姓名 学号 成绩
		  ... ... ...
		第 n+1 行：第 n 个学生的姓名 学号 成绩

		其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，
		这里保证在一组测试用例中没有两个学生的成绩是相同的。

		输出格式：
		对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，
		第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。

		输入样例：
		3
		Joe Math990112 89
		Mike CS991301 100
		Mary EE990830 95

		输出样例：
		Mike CS991301
		Joe Math990112
*/


/*
	题目分析：

		(1) 每读入一行信息，都比较一下成绩，如果大于当前的最高成绩，则替换最高成绩并记录信息；
			如果小于当前的最低成绩，则替换最低成绩并记录信息。
			最后输出最高成绩和最低成绩的信息。
			
		(2) 注意初始化成绩的最大值为-1，最小值为101，因为题目的成绩有效范围为0-100,这样可以保证最大值和最小值得到更新
*/

/*
	代码实现
*/

#include <iostream>
using namespace std;

int main()
{
	// 输入行号
	int n;
	cin >> n;

	// 最高成绩和最低成绩
	int max_score = -1;
	int min_score = 101;
	
	// 最高分与最低分学生的名称和学号信息
	string max_name, max_number, min_name,min_number;
	
	// 临时变量，记录每一行输入的学生信息
	string name, number;
	int score;

	for (int i = 0; i < n; ++i)
	{
		cin >> name >> number >> score;

		// 最高成绩
		if (score > max_score)
		{
			max_score = score;
			max_name = name;
			max_number = number;
		}

		// 最低成绩
		if (score < min_score)
		{
			min_score = score;
			min_name = name;
			min_number = number;
		}
	}

	// 输出
	cout << max_name << " " << max_number << endl;
	cout << min_name << " " << min_number;

	return 0;
}
