#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
	int n, m, pos;
	scanf("%d", &n);
	getchar();
	string info, id;
	vector<unordered_map<string, set<string>>> v(6);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6; ++j) {
			getline(cin, info);
			if (j == 0) id = info;
			else if (j != 3) v[j][info].emplace(id);
			else {
				string word;
				for (auto& iter : info) {
					if (iter != ' ') word += iter;
					else {
						v[3][word].emplace(id);
						word.clear();
					}
				}
				if (!word.empty()) v[3][word].emplace(id);
			}
		}
	}
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; ++i) {
		getline(cin, info);
		printf("%s\n", info.c_str());
		pos = info[0] - '0';
		info = info.substr(3);
		if (!v[pos].count(info)) printf("Not Found\n");
		for (auto& i : v[pos][info]) printf("%s\n", i.c_str());
	}
	return 0;
}
