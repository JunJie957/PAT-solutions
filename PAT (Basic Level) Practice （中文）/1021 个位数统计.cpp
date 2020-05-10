#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int arr[10] = { 0 };
	for (int i = 0; i < s.size(); ++i)
		arr[s[i] - '0']++;

	for (int i = 0; i < 10; ++i)
		if (arr[i] != 0) cout << i << ":" << arr[i] << endl;

	return 0;
}
