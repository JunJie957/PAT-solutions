#include <iostream>
using namespace std;

struct addr {
	char data;
	int next;
	bool mark;
} arr[100001];

int main() {
	int h1, h2, n, loc = 0;
	scanf("%d%d%d", &h1, &h2, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &loc);
		cin >> arr[loc].data >> arr[loc].next;
		arr[loc].mark = false;
	}

	while (h1 != -1) {
		arr[h1].mark = true;
		h1 = arr[h1].next;
	}

	bool flag = false;
	while (h2 != -1) {
		if (arr[h2].mark == true) {
			printf("%05d", h2);
			flag = true;
			break;
		}
		h2 = arr[h2].next;
	}
	if (flag == false) printf("-1");
 	return 0;
}
