#include <iostream>
#include <vector>
using namespace std;
vector<string> day{ "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	bool first = false;
	for (int i = 0; i < s1.length(); ++i) {
		if (!first) {
			if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
				cout << day[s1[i] - 'A'] << " ";
				first = true;
			}
		} else if (s1[i] == s2[i]) {
			if (s1[i] >= '0' && s1[i] <= '9') {
				cout << "0" << s1[i] << ":"; break;
			} else if (s1[i] >= 'A' && s1[i] <= 'N') {
				cout << s1[i] - 'A' + 10 << ":"; break;
			}
		}
	}
	for (int i = 0; i < s3.length(); ++i) {
		if (isalpha(s3[i]) && s3[i] == s4[i]) {
			printf("%02d", i); break;
		}
	}
	return 0;
}
