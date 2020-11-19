#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	string num;
	cin >> num;
	unordered_map<char, int> um;
	for (auto& iter : num) ++um[iter];
	int add = 0;
	string ans;
	for (int i = num.length() - 1; i >= 0; --i) {
		int temp = (num[i] - '0') * 2 + add;
		ans += temp % 10 + '0';
		add = temp / 10;
	}
	if (add != 0) ans += add + '0';
	reverse(ans.begin(), ans.end());
	for (auto& iter : ans) {
		if (--um[iter] == 0) um.erase(iter);
	}
	printf("%s\n%s", um.empty() ? "Yes" : "No", ans.c_str());
	return 0;
}
