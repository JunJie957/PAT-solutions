#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	s.insert(0, 4 - s.size(), '0');
	do {
		string a = s, b = s;
		sort(a.begin(), a.end(), greater<char>());
		sort(b.begin(), b.end(), less<char>());
		s = to_string(stoi(a) - stoi(b));
		s.insert(0, 4 - s.size(), '0');
		cout << a << " - " << b << " = " << s << endl;
	} while (s.compare("6174") != 0 && s.compare("0000") != 0);
	return 0;
}
