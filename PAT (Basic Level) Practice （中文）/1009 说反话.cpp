#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string str, word;
	getline(cin, str);
	vector<string> v;
	for (auto& iter : str) {
		if (iter == ' ') {
			v.emplace_back(word);
			word.clear();
		} else {
			word += iter;
		}
	}
	v.emplace_back(word);
	for (int i = v.size() - 1; i >= 0; --i) {
		printf("%s", v[i].c_str());
		if (i != 0) printf(" ");
	} 
	return 0;
}
