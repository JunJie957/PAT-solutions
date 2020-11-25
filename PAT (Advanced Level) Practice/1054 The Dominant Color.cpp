#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int most = n * m / 2, color;
	unordered_map<int, int> um;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &color);
			if (++um[color] > most) {
				printf("%d", color);
				break;
			 }
		}
	}
	return 0;
}
