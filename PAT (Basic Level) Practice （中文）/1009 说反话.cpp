/*
	��Ŀ������ 
	
		1009 ˵���� (20��)
		����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

		�����ʽ��
		�����������һ��������������һ���ڸ����ܳ��Ȳ����� 80 ���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮���� 1 ���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�

		�����ʽ��
		ÿ���������������ռһ�У���������ľ��ӡ�

		����������
		Hello World Here I Come
    
		���������
		Come I Here World Hello
*/

/*
	��Ŀ������
		
		(1) ������������������������뵽ջ���Ƚ����

		(2) �ȱ������仰������ĸ��ɵ��ʣ�Ȼ�󽫵���������ջ

		(3) ����������������γ�ջ����ջʱҪע�����һ�����ʲ����пո�
*/

/*
	����ʵ��
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
