#include <iostream>
using namespace std;
int main() {
	int g1, s1, k1, g2, s2, k2, add = 0;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	if (g1 > g2 || (g1 == g2 && s1 > s2) || (g1 == g2 && s1 == s2 && k1 > k2)) {
		swap(g1, g2); swap(s1, s2); swap(k1, k2); printf("-");
	}
	if (k2 < k1) {
		k2 += 29; 
		add = 1;
	}
	k2 -= k1;
	if (s2 - add < s1) {
		s2 = s2 - s1 - add + 17; 
		add = 1;
	} else {
		s2 = s2 - s1 - add;
		add = 0;
	}
	g2 = g2 - g1 - add;
	printf("%d.%d.%d", g2, s2, k2);
	return 0;
}
