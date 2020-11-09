#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	string res = str.substr(0, str.find('E'));		// 小数
	int num = stoi(str.substr(str.find('E') + 1));	// 指数
	int point = res.find('.');
	if (num >= 0) {
		int dis = res.length() - point - 1;
		if (dis <= num) {
			res.erase(res.begin() + point);
			dis = res.length() - point - 1;
			for (int i = num - dis - 1; i > 0; --i) res += "0";
		} else {
			res.insert(point + num + 1, ".");
			res.erase(res.begin() + point);
		}
	} else {
		res.erase(res.begin() + point);
		for (int i = 0; i < -num; ++i) res.insert(1, "0");
		res.insert(2, ".");
	}
	if (res[0] == '+') res.erase(res.begin());
	cout << res;
	return 0;
}
