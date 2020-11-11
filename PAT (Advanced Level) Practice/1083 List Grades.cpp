#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stu {
	int s;
	string name, id;
};
int main() {
	int n, g1, g2;
	scanf("%d", &n);
	vector<stu> lists(n), ans;
	while (--n >= 0) cin >> lists[n].name >> lists[n].id >> lists[n].s;
	scanf("%d%d", &g1, &g2);
	for (auto& i : lists) if (i.s >= g1 && i.s <= g2) ans.emplace_back(i);
	sort(ans.begin(), ans.end(), [=](stu& s1, stu& s2) { return s1.s > s2.s; });
	for (auto& iter : ans) printf("%s %s\n", iter.name.c_str(), iter.id.c_str());
	if (ans.empty()) printf("NONE");
	return 0;
}
