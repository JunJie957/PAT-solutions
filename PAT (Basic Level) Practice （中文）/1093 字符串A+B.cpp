#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);

	int lena = a.size();
	unordered_set<char> s;
	for (int i = 0; i < lena; ++i)
	{
		auto iter = s.find(a[i]);
		if (iter == s.end())
		{
			printf("%c", a[i]);
			s.insert(a[i]);
		}
	}

	int lenb = b.size();
	for (int i = 0; i < lenb; ++i)
	{
		auto iter = s.find(b[i]);
		if (iter == s.end())
		{
			printf("%c", b[i]);
			s.insert(b[i]);
		}
	}

	return 0;
}
