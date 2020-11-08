#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> power{ 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
map<int, char> m{ {0,'1'}, {1,'0'}, {2,'X'}, {3,'9'} ,{4,'8'}, {5,'7'},
				  {6,'6'}, {7,'5'}, {8,'4'}, {9,'3'}, {10,'2'}, };
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		int sum = 0, flag = 1;
		for (int i = 0; i < 17; ++i) {
			if (s[i] < '0' || s[i] > '9') {
				flag = 0; break;
			}
			sum += (s[i] - '0') * power[i];
		}
		if (flag && m[sum % 11] == s.back()) {
			++cnt;
		} else {
			cout << s << endl;
		}
	}
	if (cnt == n) cout << "All passed";
	return 0;
}
