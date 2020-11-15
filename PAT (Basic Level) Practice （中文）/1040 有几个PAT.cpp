#include <iostream>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	int len = str.length();
	vector<int> p(len, 0);
	for (int i = 0; i < len; ++i) {
		if (i > 0) p[i] = p[i - 1];
		if (str[i] == 'P') ++p[i];
	}
	int t = 0, ans = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] == 'T') ++t;
		else if (str[i] == 'A' && t > 0 && p[i] > 0) {
			ans = (ans + t * p[i]) % 1000000007;
		}
	}
	printf("%d", ans);
	return 0;
}
