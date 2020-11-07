#include <iostream>
using namespace std;
int main() {
	char c;
	int n, line = 1, base = 3;
	scanf("%d %c", &n, &c);
	n -= 1;
	while (n >= base * 2) {
		n -= base * 2;  // 计算能用掉多少个符号
		base += 2;
		line += 2;		// 计算行数
	}
	int space = 0, start = line;
	for (int i = 1; i <= line; ++i) {
		for (int j = 0; j < space; ++j)  printf(" ");
		for (int k = start; k >= 1; --k) printf("%c", c);
		printf("\n");
		if (i <= line / 2) {
			++space;
			start -= 2;
		} else {
			--space;
			start += 2;
		}
	}
	printf("%d", n); // 打印剩余未使用符号的数量
	return 0;
}
