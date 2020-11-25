
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	stack<int> st;
	vector<int> arr(n);
	while (k--) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int cur = 0;
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			st.emplace(i);
			if (st.size() > m) {
				flag = false;
				break;
			}
			while (!st.empty() && st.top() == arr[cur]) {
				st.pop();
				++cur;
			}
		}
		if (st.empty() && flag == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
			while (!st.empty()) st.pop();
		}
	}
	return 0;
}
