#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	// n - the total number of applicants
	// m - the total number of graduate schools
	// k - the number of choices an applicant may have.
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	// school : [0, M-1]
	// The i-th integer is the quota of the i-th graduate school respectively.
	vector<int> school(m);
	for (int i = 0; i < m; ++i) scanf("%d", &school[i]);

	// applicants: [0,N-1]
	// Ge  Gi K num...

	/*
		0 - number
		1 - Ge
		2 - Gi
		3 - final grade
		[4, 4 + K - 1] - choice
	*/
	vector<vector<int>> ans(n, vector<int>(4 + k, 0));
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &ans[i][1], &ans[i][2]);  
		for (int j = 0; j < k; ++j) scanf("%d", &ans[i][4 + j]);
		ans[i][0] = i; // 位置号 
		ans[i][3] = (ans[i][1] + ans[i][2]) / 2;  // 总分 
	}
	
	// 排序依据：1、总分 2、Ge分数 
	sort(ans.begin(), ans.end(), [=](vector<int>& v1, vector<int>& v2) {
		if (v1[3] != v2[3]) return v1[3] > v2[3];
		return v1[1] > v2[1];
		});

	// 排名
	for (int i = 0; i < n; ++i) {
		if (i > 0 && ans[i][3] == ans[i - 1][3] && ans[i][1] == ans[i - 1][1]) {
			ans[i].emplace_back(ans[i - 1].back());
		}
		else {
			ans[i].emplace_back(i + 1);
		}
	}

	vector<vector<int>> res(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 4; j < 4 + k; ++j) {
			if (school[ans[i][j]] > 0) {
				res[ans[i][j]].emplace_back(ans[i][0]);
				--school[ans[i][j]]; // 录取名额减少
				
				// 排名相同 且 志愿相同
				for (int s = i + 1; s < n; ++s) {
					if (ans[s].back() == ans[i].back()) {
						bool same = true; // same applicants  
						for (int f = 4; f < 4 + k; ++f) {
							if (ans[i][f] != ans[s][f]) {
								same = false;
								break;
							}
						}
						if (same) {
							res[ans[s][j]].emplace_back(ans[s][0]);
							--school[ans[i][j]]; // 录取名额减少
							++i;
						}
					} else break;
				}
				break;
			}
		}
	}
	// output 
	for (int i = 0; i < m; ++i) {
		sort(res[i].begin(), res[i].end());
		for (int j = 0; j < res[i].size(); ++j) {
			if (j != 0) cout << " ";
			cout << res[i][j];
		}
		if (i != m - 1 || res[i].empty()) cout << endl;
	}
	return 0;
}
