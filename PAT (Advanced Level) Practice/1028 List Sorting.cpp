#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stu { string id, name, score; };
int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	vector<stu> list(n);
	for (int i = 0; i < n; ++i) cin >> list[i].id >> list[i].name >> list[i].score;
	sort(list.begin(), list.end(), [=](stu& s1, stu& s2) {
		if (c == 1) return s1.id < s2.id;
		else if (c == 2) return s1.name == s2.name ? s1.id < s2.id : s1.name < s2.name;
		else if (c == 3) return s1.score == s2.score ? s1.id < s2.id : s1.score < s2.score;
		});
	for (auto& i : list) printf("%s %s %s\n", i.id.c_str(), i.name.c_str(), i.score.c_str());
	return 0;
}
