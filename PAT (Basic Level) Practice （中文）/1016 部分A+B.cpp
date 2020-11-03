#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b, c, d, r1, r2;
    cin >> a >> b >> c >> d;
    int cnt1 = 0, cnt2 = 0;

    for (auto& iter : a) if (iter == b[0]) ++cnt1;
    for (auto& iter : c) if (iter == d[0]) ++cnt2;

    while (--cnt1 >= 0) r1 += b[0];
    while (--cnt2 >= 0) r2 += d[0];

    int sum = 0;
    if (!r1.empty()) sum += stoi(r1);
    if (!r2.empty()) sum += stoi(r2);
    printf("%d", sum);
    return 0;
}
