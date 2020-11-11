#include <iostream>
#include <string>
using namespace std;
string num[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string wei[5] = { "Shi","Bai","Qian","Wan","Yi" };
int main() {
	string str;
	getline(cin, str);
	int len = str.size(), left = 0, right = len - 1;
	if (str[0] == '-') {
		printf("Fu");
		++left;
	}
	while (left + 4 <= right) right -= 4;
	while (left < len) {
		bool is_zero = false, isPrint = false;
		while (left <= right) {
			if (left > 0 && str[left] == '0') {
				is_zero = true;
			} else {
				if (is_zero) {
					cout << " ling"; 
					is_zero = false;
				}
				if (left > 0) cout << " ";
				cout << num[str[left] - '0'];
				if (left != right) cout << " " << wei[right - left - 1];
				isPrint = true;
			}
			++left;
		}
		if (isPrint == true && right != len - 1) cout << " " << wei[(len - 1 - right) / 4 + 2];
		right += 4;
	}
	return 0;
}
