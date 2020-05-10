#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool greater_compare(char& a, char& b)
{
	return a > b;
}

int main()
{
	string s;
	cin >> s;
	s.insert(0, 4 - s.size(), '0');	// 位数不足四位的话，需要在前面补0
	string a, b;

	do
	{
		a = b = s;
		sort(a.begin(), a.end(), greater_compare);
		sort(b.begin(), b.end());
		s = to_string(stoi(a.c_str()) - stoi(b.c_str()));
		s.insert(0, 4 - s.size(), '0'); // 位数不足四位的话，需要在前面补0
		cout << a << " - " << b << " = " << s << endl;
	} while (s.compare("6174") != 0 && s.compare("0000") != 0);

	return 0;
}
