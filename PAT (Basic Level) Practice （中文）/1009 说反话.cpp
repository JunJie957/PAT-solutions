/*
	题目描述： 
	
		1009 说反话 (20分)
		给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

		输入格式：
		测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

		输出格式：
		每个测试用例的输出占一行，输出倒序后的句子。

		输入样例：
		Hello World Here I Come
    
		输出样例：
		Come I Here World Hello
*/

/*
	题目分析：
		
		(1) 将单词逆序输出，很容易联想到栈：先进后出

		(2) 先遍历整句话，将字母组成单词，然后将单词依次入栈

		(3) 输出，即将单词依次出栈，出栈时要注意最后一个单词不能有空格
*/

/*
	代码实现
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	string tmp;
	stack<string> st;

	getline(cin, s);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
			tmp += s[i];
		
		if ((s[i] == ' ' && tmp.size() != 0) || i == s.size() - 1)
		{
			st.push(tmp);
			tmp.clear();
		}
	}

	while (st.size() > 0)
	{
		if (st.size() > 1) cout << st.top() << " ";
		else cout << st.top();

		st.pop();
	}

	return 0;
}
