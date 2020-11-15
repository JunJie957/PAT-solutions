#include <iostream>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	int len = str.length();
	vector<int> cp(len, 0);
	for (int i = 0; i < len; ++i) {
		if (i > 0) cp[i] = cp[i - 1];
		if (str[i] == 'P') cp[i] += 1;
	}
	int t = 0, sum = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] == 'T') ++t;
		else if (str[i] == 'A' && t > 0 && cp[i] > 0) {
			sum = (sum + cp[i] * t) % 1000000007;
		}
	}
	printf("%d", sum);
	return 0;
}
