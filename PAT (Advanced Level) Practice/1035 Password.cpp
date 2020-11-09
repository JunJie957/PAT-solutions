#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	string name,password;
	vector<pair<string, string>> ans;
	for (int i = 0; i < n; ++i) {
		cin >> name >> password;
		string temp = password;
		for (auto& iter : temp) {
			if (iter == '1') iter = '@';
			else if (iter == '0') iter = '%';
			else if (iter == 'l') iter = 'L';
			else if (iter == 'O') iter = 'o';
		}
		if (temp.compare(password) != 0) ans.emplace_back(name, temp);
	}
	if (ans.empty() && n == 1) printf("There is 1 account and no account is modified");
	else if (ans.empty()) printf("There are %d accounts and no account is modified", n);
	else {
		printf("%d\n", ans.size());
		for (auto& iter : ans) printf("%s %s\n", iter.first.c_str(), iter.second.c_str());
	}
	return 0;
}
