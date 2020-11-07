#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	string res;
	int num = a + b;
	do {
		res += to_string(num % d);
		num /= d;
	} while (num != 0);
	for (auto iter = res.rbegin(); iter != res.rend(); ++iter) cout << *iter;
	return 0;
}
