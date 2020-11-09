#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b, cnt = 0;
	scanf("%d%d", &a, &b);
	string str = to_string(a + b);
	if (str[0] == '-') {
		cout << "-";
		str.erase(str.begin());
	}
	string res;
	for (int i = str.length() - 1; i >= 0; --i) {
		if (cnt == 3) {
			res += ",";
			cnt = 0;
		}
		res += str[i];
        ++cnt;
	}
	for (int i = res.length() - 1; i >= 0; --i) cout << res[i];
	return 0;
}
