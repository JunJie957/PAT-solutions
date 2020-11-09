#include <iostream>
#include <string>
using namespace std;
string word[] = { "zero" , "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main() {
	string str;
	cin >> str;
	int sum = 0;
	for (auto& iter : str) sum += iter - '0';
	str = to_string(sum);
	for (int i = 0; i < str.length(); ++i) {
		if (i != 0) printf(" ");
		printf("%s", word[str[i] - '0'].c_str());
	}
	return 0;
}
