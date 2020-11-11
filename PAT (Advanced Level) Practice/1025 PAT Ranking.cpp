#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct TestInfo {
	string id;
	int score, frank, loc, lrank;
};
int main() {
	int n, k, loc_num = 1;
	scanf("%d", &n);
    TestInfo temp;
	vector<TestInfo> lists;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		vector<TestInfo> v;
		for (int i = 0; i < k; ++i) {
			cin >> temp.id >> temp.score;
			temp.loc = loc_num;
			v.emplace_back(temp);
		}
		sort(v.begin(), v.end(), [](TestInfo& s1, TestInfo& s2) {return s1.score > s2.score; });
		for (int i = 0; i < v.size(); ++i) {
			if (i > 0 && v[i].score == v[i - 1].score) v[i].lrank = v[i - 1].lrank;
			else v[i].lrank = i + 1;
		}
		for (auto& iter : v) lists.emplace_back(iter);
        ++loc_num;
	}
	sort(lists.begin(), lists.end(), [](TestInfo& s1, TestInfo& s2) {
		return s1.score != s2.score ? s1.score > s2.score : s1.id < s2.id;
		});
	cout << lists.size() << endl;
	for (int i = 0; i < lists.size(); ++i) {
		cout << lists[i].id << " ";
		if (i > 0 && lists[i].score == lists[i - 1].score) {
			lists[i].frank = lists[i - 1].frank;
			cout << lists[i - 1].frank;
		} else {
			lists[i].frank = i + 1;
			cout << lists[i].frank;
		}
		cout << " " << lists[i].loc << " " << lists[i].lrank << endl;
	}
	return 0;
}
