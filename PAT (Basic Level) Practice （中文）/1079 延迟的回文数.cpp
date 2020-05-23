#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string my_add(string s1, string s2)
{
	int len = s1.length();
	string res;
	int adv = 0;
	int val = 0;
	for(int i = len - 1; i >= 0; --i)
	{
		val = (s1[i] - '0' + s2[i] - '0' + adv) % 10;
		adv = (s1[i] - '0' + s2[i] - '0' + adv) / 10;
		res += (val + '0');
	}
	if (adv != 0) res += (adv + '0');
		
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string str;
	cin >> str;

	int count = 0;
	string rev = str;
	reverse(rev.begin(), rev.end());

	while (str != rev && count < 10)
	{
		string tmp = my_add(str, rev);
		printf("%s + %s = %s\n", str.c_str(), rev.c_str(), tmp.c_str());

		rev = str = tmp;
		reverse(rev.begin(), rev.end());
		++count;
	}

	if (str.compare(rev) == 0 && count < 10)
		cout << str << " is a palindromic number.";
	else if (str.compare(rev) != 0 && count >= 10)
		cout << "Not found in 10 iterations.";

	return 0;
}
