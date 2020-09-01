#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	string id, in, out, earlier = "23:59:59", last = "00:00:00", earlier_id, last_id;
	for (int i = 0; i < m; ++i) {
		cin >> id >> in >> out;
		if (in.compare(earlier) < 0) { /* 最早到达 */
			earlier = in;
			earlier_id = id;
		}
		if (out.compare(last) > 0) { /* 最晚离开 */
			last = out;
			last_id = id;
		}
	}
	printf("%s %s", earlier_id.c_str(), last_id.c_str());
	return 0;
}
