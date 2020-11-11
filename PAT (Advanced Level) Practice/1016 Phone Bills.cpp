#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, int> p;
typedef pair<double, int> p2;
vector<int> rate(25, 0);
bool CheckIsPair(vector<p>& v) {
	for (int i = 0; i < v.size() - 1; ++i)
		if (v[i].second == 1 && v[i + 1].second == 0) return true;
	return false;
}
p2 CalculateTime(string& t1, string& t2) {
	int m1 = stoi(t1.substr(9, 2)), m2 = stoi(t2.substr(9, 2));
	int h1 = stoi(t1.substr(6, 2)), h2 = stoi(t2.substr(6, 2));
	int d1 = stoi(t1.substr(3, 2)), d2 = stoi(t2.substr(3, 2));
	double s1 = m1 * rate[h1] + rate[24] * d1 * 60;
	double s2 = m2 * rate[h2] + rate[24] * d2 * 60;
	for (int i = 0; i < h1; ++i) s1 += rate[i] * 60;
	for (int i = 0; i < h2; ++i) s2 += rate[i] * 60;
	double sum = (s2 - s1) / 100.0;
	int time = d2 * 24 * 60 + h2 * 60 + m2 - d1 * 24 * 60 - h1 * 60 - m1;
	return { sum, time }; // 总花费 + 总时间
}
int main() {
	for (int i = 0; i < 24; ++i) {
		scanf("%d", &rate[i]);
		rate[24] += rate[i];
	}
	int n;
	scanf("%d", &n);
	string name, date, status;
	map<string, vector<p>> m;
	for (int i = 0; i < n; ++i) {
		cin >> name >> date >> status;
		m[name].push_back({ date, status[1] == 'n' ? 1 : 0 });
	}
	for (auto& iter : m) {
		auto v = iter.second;
		sort(v.begin(), v.end(), [](p& p1, p& p2) { return p1.first < p2.first; });
		if (CheckIsPair(v) == false) continue;
		cout << iter.first << " " << v[0].first.substr(0, 2) << endl;
		double total_sum = 0;
		for (int i = 0; i < v.size() - 1; ++i) {
			if (v[i].second == 1 && v[i + 1].second == 0) {
				p2 res = CalculateTime(v[i].first, v[i + 1].first);
				printf("%s %s %d $%.2f\n", v[i].first.substr(3).c_str(), v[i + 1].first.substr(3).c_str(), res.second, res.first);
				total_sum += res.first;
				++i;
			}
		}
		printf("Total amount: $%.2f\n", total_sum);
	}
	return 0;
}
