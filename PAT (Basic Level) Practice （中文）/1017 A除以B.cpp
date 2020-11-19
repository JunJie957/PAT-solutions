#include <iostream>
#include <string>
using namespace std;
int main() {
	int r;
	string s;
	cin >> s >> r;
	int len = s.length();
	int a = (s[0] - '0') / r;
	int b = (s[0] - '0') % r;
	if (a != 0 || len == 1) printf("%d", a);
	for (int i = 1; i < len; ++i) {
		b = b * 10;
		a = ((s[i] - '0') + b) / r;
		b = ((s[i] - '0') + b) % r;
		printf("%d", a);
	}
	printf(" %d", b);
	return 0;
}
