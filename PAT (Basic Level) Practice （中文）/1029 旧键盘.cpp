#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string full_str, lack_str;
	cin >> full_str >> lack_str;

	set<char> s;
	char tmp;
	int loc = -1;
	for (int i = 0; i < full_str.size(); ++i)
	{
		tmp = full_str[i];
		loc = lack_str.find(tmp);
		if (loc == -1)
		{
			if (tmp >= 'a' && tmp <= 'z') tmp -= 32;
			if (s.find(tmp) == s.end())
			{
				cout << tmp;
				s.insert(tmp);
			}
		}
	}
	return 0;
}
