#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct person {
	int age, worth;
	string name;
};
int main() {
	int n, k, sum, amin, amax;
	scanf("%d%d", &n, &k);
	vector<person> list(n);
	while (--n >= 0) cin >> list[n].name >> list[n].age >> list[n].worth;
	sort(list.begin(), list.end(), [=](person& p1, person& p2) {
		if (p1.worth != p2.worth) return p1.worth > p2.worth;
		if (p1.age != p2.age) return p1.age < p2.age;
		return p1.name < p2.name;
		});
	for (int i = 0; i < k; ++i) {
		scanf("%d%d%d", &sum, &amin, &amax);
		vector<person> temp;
		for (auto& i : list) {
			if (i.age >= amin && i.age <= amax) {
				temp.emplace_back(i);
				if (temp.size() == sum) break;
			}
		}
		printf("Case #%d:\n", i + 1);
		if (temp.empty()) printf("None\n");
		for (auto& i : temp) printf("%s %d %d\n", i.name.c_str(), i.age, i.worth);
	}
	return 0;
}
