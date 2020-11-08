#include <iostream>
using namespace std;
int main() {
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	char list[] = { "0123456789ABC" };
	printf("#%c%c%c%c%c%c", list[r / 13], list[r % 13], list[g / 13], list[g % 13], list[b / 13], list[b % 13]);
	return 0;
}
