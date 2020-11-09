#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	bool flag = true;	// true - ÆæÊý
	while (a.length() < b.length()) a.insert(0, "0");
	while (a.length() > b.length()) b.insert(0, "0");
	for (int i = b.length() - 1; i >= 0; --i) {
		if (flag) {
			int add = ((b[i] - '0') + (a[i] - '0')) % 13;
			if (add < 10) b[i] = add + '0';
			else if (add == 10) b[i] = 'J';
			else if (add == 11) b[i] = 'Q';
			else if (add == 12) b[i] = 'K';
			flag = false;
		}
		else {
			int sub = ((b[i] - '0') - (a[i] - '0'));
			if (sub < 0) sub += 10;
			b[i] = sub + '0';
			flag = true;
		}
	}
	cout << b;
	return 0;
}
