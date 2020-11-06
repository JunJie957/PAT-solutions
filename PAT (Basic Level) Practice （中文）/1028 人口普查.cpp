#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    string name, date, old, young;
    int y1 = 2014, m1 = 9, d1 = 6, y2 = 1814, m2 = 9, d2 = 6;
    for (int i = 0; i < n; ++i) {
        cin >> name >> date;
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
        if (y < 1814 || y > 2014 || (y == 1814 && m < 9) || (y == 2014 && m > 9) || (y == 1814 && m == 9 && d < 6) || (y == 2014 && m == 9 && d > 6)) continue;
        ++cnt; // 记录有效的日子个数
        if (y < y1 || (y == y1 && m < m1) || (y == y1 && m == m1 && d < d1)) {
            old = name; y1 = y; m1 = m; d1 = d;
        }
        if (y > y2 || (y == y2 && m > m2) || (y == y2 && m == m2 && d > d2)) {
            young = name; y2 = y; m2 = m; d2 = d;
        }
    }
    cout << cnt;
    if (!old.empty()) cout << " " << old;
    if (!young.empty()) cout << " " << young;
    return 0;
}
