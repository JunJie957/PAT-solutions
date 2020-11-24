#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
	int most = 0;
	string speech, word;
	getline(cin, speech);
	set<string> s;
	unordered_map<string, int> um;
	for (auto& iter : speech) {
		if (isalnum(iter)) word += tolower(iter);
		else if (!word.empty()) {
			most = max(++um[word], most);
			word.clear();
		}
	}
	if (!word.empty()) most = max(++um[word], most);
	for (auto& i : um) if (i.second == most) s.emplace(i.first);
	for (auto& i : s) printf("%s ", i.c_str());
	printf("%d", most);
	return 0;
}
