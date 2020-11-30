#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, pos = 0;
vector<int> number, cbt;
void InOrder(int root) {
	if (root > n)  return;
	InOrder(root * 2);
	cbt[root] = number[pos++];
	InOrder(root * 2 + 1);
}
int main() {
	scanf("%d", &n);
	number.resize(n), cbt.resize(n + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &number[i]);
	}
	sort(number.begin(), number.end());
	InOrder(1);
	for (int i = 1; i <= n; ++i) {
		printf("%d", cbt[i]);
		if (i < n) printf(" ");
	}
	return 0;
}
