#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	string s1, s2, res;
	getline(cin, s1);
	getline(cin, s2);

	unordered_set<char> us;
	for (const auto& iter : s2) {
		us.insert(iter);
	}

	for (const auto& iter : s1) {
		if (us.find(iter) == us.end()) {
			res += iter;
		}
	}

	printf("%s", res.c_str());
 	return 0;
}
