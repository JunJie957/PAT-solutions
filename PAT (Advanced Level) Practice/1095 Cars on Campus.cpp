#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct CarInfo { string id, time, status; };
int main() {
	int n, m, max_time = 0;
	scanf("%d%d", &n, &m);
	CarInfo temp;
	unordered_map<string, vector<CarInfo>> um;
	for (int i = 0; i < n; ++i) {
		cin >> temp.id >> temp.time >> temp.status;
		um[temp.id].emplace_back(temp);
	}

	vector<CarInfo> valid;
	map<string, int> parking;
	for (auto& iter : um) {
		parking[iter.first] = 0;
		auto m = iter.second;
		sort(m.begin(), m.end(), [](CarInfo& c1, CarInfo& c2) { return c1.time < c2.time; });
		for (int i = 0; i < m.size() - 1; ++i) {
			if (m[i].status == "in" && m[i + 1].status == "out") {
				int h1 = stoi(m[i].time.substr(0, 2)), h2 = stoi(m[i + 1].time.substr(0, 2));
				int m1 = stoi(m[i].time.substr(3, 2)), m2 = stoi(m[i + 1].time.substr(3, 2));
				int s1 = stoi(m[i].time.substr(6, 2)), s2 = stoi(m[i + 1].time.substr(6, 2));
				parking[iter.first] += (h2 * 60 * 60 + m2 * 60 + s2) - (h1 * 60 * 60 + m1 * 60 + s1);
				max_time = max(max_time, parking[iter.first]);
				valid.emplace_back(m[i]);
				valid.emplace_back(m[i + 1]);
				++i;
			}
		}
	}
	sort(valid.begin(), valid.end(), [](CarInfo& p1, CarInfo& p2) { return p1.time < p2.time; });

	char time[10];
	int loc = 0, numCar = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%s", time);
		while (loc < valid.size() && valid[loc].time <= time) {
			if (valid[loc].status.compare("in") == 0) ++numCar;
			else --numCar;
			++loc;
		}
		printf("%d\n", numCar);
	}
	for (auto& iter : parking) if (iter.second == max_time) printf("%s ", iter.first.c_str());
	printf("%02d:%02d:%02d", max_time / 3600, max_time % 3600 / 60, max_time % 60);
	return 0;
}
