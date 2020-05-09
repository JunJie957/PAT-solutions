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
