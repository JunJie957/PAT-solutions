#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string name, passwd;
	int count_not_modify = 0;
	vector<pair<string, string>> v;
	for (int i = 0; i < n; ++i) {
		cin >> name >> passwd;
		// ’“√‹¬Î
		if (passwd.find('1') != passwd.npos || passwd.find('0') != passwd.npos
			|| passwd.find('l') != passwd.npos || passwd.find('O') != passwd.npos) {
			for (auto& iter : passwd) { // –ﬁ∏ƒ√‹¬Î
				if (iter == '1') iter = '@';
				else if (iter == '0') iter = '%';
				else if (iter == 'l') iter = 'L';
				else if (iter == 'O') iter = 'o';
			}
			v.push_back(make_pair(name, passwd));
		}
		else {
			++count_not_modify;
		}
	}

	if (v.size() == 0) {
		if (count_not_modify == 1) 
			printf("There is 1 account and no account is modified");
		else 
			printf("There are %d accounts and no account is modified", n);
	}
	else {
		printf("%d\n", v.size());
		for (const auto& iter : v)
			printf("%s %s\n", iter.first.c_str(), iter.second.c_str());
	}
	return 0;
}
