#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct stu {
	string num;
	int sa;
	int sb;
	int sum;
};
bool cmp(stu& s1, stu& s2) {
	return s1.sum != s2.sum ? s1.sum > s2.sum : s1.sa != s2.sa ? s1.sa > s2.sa : s1.num < s2.num;
}
int main() {
	int n, low, high;
	scanf("%d%d%d", &n, &low, &high);
	stu s;
	vector<stu> L1, L2, L3, L4;
	for (int i = 0; i < n; ++i) {
		cin >> s.num >> s.sa >> s.sb;
		if (s.sa >= low && s.sb >= low) {
			s.sum = s.sa + s.sb;
			if (s.sa >= high && s.sb >= high) L1.emplace_back(s);
			else if (s.sa >= high) L2.emplace_back(s);
			else if (s.sa >= s.sb) L3.emplace_back(s);
			else L4.emplace_back(s);
		}
	}
	cout << L1.size() + L2.size() + L3.size() + L4.size() << endl;
	sort(L1.begin(), L1.end(), cmp);
	sort(L2.begin(), L2.end(), cmp);
	sort(L3.begin(), L3.end(), cmp);
	sort(L4.begin(), L4.end(), cmp);
	for (auto& iter : L1) cout << iter.num << " " << iter.sa << " " << iter.sb << endl;
	for (auto& iter : L2) cout << iter.num << " " << iter.sa << " " << iter.sb << endl;
	for (auto& iter : L3) cout << iter.num << " " << iter.sa << " " << iter.sb << endl;
	for (auto& iter : L4) cout << iter.num << " " << iter.sa << " " << iter.sb << endl;
	return 0;
}
