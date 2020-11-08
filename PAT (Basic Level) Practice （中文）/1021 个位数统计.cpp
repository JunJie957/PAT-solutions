#include <iostream>
#include <map>
using namespace std;
int main() {
	string str;
	cin >> str;
	map<char, int> m;
	for (auto& iter : str) ++m[iter];
	for (auto& iter : m) printf("%c:%d\n", iter.first, iter.second);
	return 0;
}
