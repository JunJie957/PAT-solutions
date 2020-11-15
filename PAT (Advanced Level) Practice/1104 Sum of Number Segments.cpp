#include <iostream>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long double sum = 0.0, temp;
	for (int i = 1; i <= n; ++i) {
		scanf("%Lf", &temp);
		sum += temp * i * (n - i + 1);
	}
	printf("%0.2Lf", sum);
	return 0;
}
