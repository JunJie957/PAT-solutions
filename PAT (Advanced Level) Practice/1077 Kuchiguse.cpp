#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	string str, ans;
	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		if (i == 0) {
			ans = str;
			continue;
		}
		int j = ans.length() - 1, k = str.length() - 1;
		while (j >= 0 && k >= 0) {
			if (ans[j] != str[k]) break;
			--j;
			--k;
		}
		if(j >= 0) ans = ans.substr(j + 1);
	}
	if (ans.empty()) cout << "nai";
	else cout << ans;
	return 0;
}
