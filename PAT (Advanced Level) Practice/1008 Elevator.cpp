#include <iostream>
using namespace std;
int main() {
	int n, floor, cur = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &floor);
		if (floor > cur) {
			sum += (floor - cur) * 6 + 5; // ио
		} else {
			sum += (cur - floor) * 4 + 5; // об
		}
		cur = floor;
	}
	printf("%d", sum);
	return 0;
}
