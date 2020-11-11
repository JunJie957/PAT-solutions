#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Rank {
	int rc, rm, re, ra;
};
bool cmp(pair<string, double>& v1, pair<string, double>& v2) {
	return v1.second > v2.second;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	string id;
	int c, m, e;
	vector<pair<string, double>> vc, vm, ve, va;
	for (int i = 0; i < n; ++i) {
		cin >> id >> c >> m >> e;
		vc.emplace_back(id, c);
		vm.emplace_back(id, m);
		ve.emplace_back(id, e);
		va.emplace_back(id, double(c + m + e) / 3.0);
	}
	sort(vc.begin(), vc.end(), cmp);
	sort(vm.begin(), vm.end(), cmp);
	sort(ve.begin(), ve.end(), cmp);
	sort(va.begin(), va.end(), cmp);
	unordered_map<string, Rank> um;
	for (int i = 0; i < n; ++i) {
		if (i > 0 && vc[i].second == vc[i - 1].second) um[vc[i].first].rc = um[vc[i - 1].first].rc;
		else um[vc[i].first].rc = i + 1;
		if (i > 0 && vm[i].second == vm[i - 1].second) um[vm[i].first].rm = um[vm[i - 1].first].rm;
		else um[vm[i].first].rm = i + 1;
		if (i > 0 && ve[i].second == ve[i - 1].second) um[ve[i].first].re = um[ve[i - 1].first].re;
		else um[ve[i].first].re = i + 1;
		if (i > 0 && va[i].second == va[i - 1].second) um[va[i].first].ra = um[va[i - 1].first].ra;
		else um[va[i].first].ra = i + 1;
	}
	for (int i = 0; i < k; ++i) {
		cin >> id;
		auto iter = um.find(id);
		if (iter != um.end()) {
			int best = min({ iter->second.rc, iter->second.rm, iter->second.re, iter->second.ra });
			cout << best << " ";
			if (iter->second.ra == best) cout << "A" << endl;
			else if (iter->second.rc == best) cout << "C" << endl;
			else if (iter->second.rm == best) cout << "M" << endl;
			else if (iter->second.re == best) cout << "E" << endl;
		}
		else cout << "N/A\n";
	}
	return 0;
}
