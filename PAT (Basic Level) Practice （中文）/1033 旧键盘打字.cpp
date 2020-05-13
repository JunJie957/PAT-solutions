#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	string bad_key, full_str;
	getline(cin, bad_key);
	getline(cin, full_str);

	int length = full_str.size();
	for (int i = 0; i < length; ++i)
	{
		if (bad_key.find(toupper(full_str[i])) != string::npos) continue;
		if (bad_key.find("+") != string::npos && isupper(full_str[i])) continue;
		cout << full_str[i];
	}
	return 0;
}
