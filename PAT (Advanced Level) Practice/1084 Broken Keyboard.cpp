#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	unordered_map<char, int> um;
	for (int i = s1.length() - 1; i >= 0; --i) {
		if (islower(s1[i])) s1[i] = toupper(s1[i]);
		um[s1[i]] = i;
	}
	for (int i = s2.length() - 1; i >= 0; --i) {
		if (islower(s2[i])) s2[i] = toupper(s2[i]);
		um.erase(s2[i]);
	}
	vector<char> res(s1.length(), ' ');
	for (auto& iter : um) res[iter.second] = iter.first;
	for (auto& iter : res) if (iter != ' ') printf("%c", iter);
	return 0;
}
