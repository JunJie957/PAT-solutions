#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int k, step = 0;
	string n;
	cin >> n >> k;
	string r = n;
	reverse(r.begin(), r.end());
	while (n.compare(r) != 0 && step < k) {
		string ans;
		int add = 0, i = r.length() - 1;
		while (i >= 0) {
			int sum = n[i] - '0' + r[i] - '0' + add;
			ans += sum % 10 + '0';
			add = sum / 10;
			--i;
		}
		if (add != 0) ans += add + '0';
		reverse(ans.begin(), ans.end());
		n = r = ans;
		reverse(r.begin(), r.end());
		++step;
	}
	printf("%s\n%d", n.c_str(), step);
	return 0;
}
