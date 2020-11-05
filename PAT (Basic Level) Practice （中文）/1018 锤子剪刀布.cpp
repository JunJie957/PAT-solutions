#include <iostream>
#include <vector>
using namespace std;

int judge(char& a, char& b) {
    if (a == b) return 1; 
    if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') ||  (a == 'B' && b == 'C')) return 2;
    return 3;
}

int main() {
    int n;
    scanf("%d", &n);
    char a, b;
    vector<vector<int>> v(2, vector<int>(3, 0));    // 记录胜平负的次数
    vector<vector<int>> w(2, vector<int>(3, 0));    // 记录胜的时候的手势
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        int res = judge(a, b);
        if (res == 1) {
            ++v[0][1]; ++v[1][1];   // 平
        } else if (res == 2) {
            ++v[0][0]; ++v[1][2];   // 甲胜
            if (a == 'C') ++w[0][0];
            else if (a == 'J') ++w[0][1];
            else if (a == 'B') ++w[0][2];
        } else if (res == 3) {
            ++v[0][2]; ++v[1][0];   // 甲输
            if (b == 'C') ++w[1][0];
            else if (b == 'J') ++w[1][1];
            else if (b == 'B') ++w[1][2];
        }
    }
    printf("%d %d %d\n%d %d %d\n", v[0][0], v[0][1], v[0][2], v[1][0], v[1][1], v[1][2]);
    if (w[0][2] >= w[0][0] && w[0][2] >= w[0][1])      printf("B");
    else if (w[0][0] >= w[0][1] && w[0][0] >= w[0][2]) printf("C");
    else if (w[0][1] >= w[0][0] && w[0][1] >= w[0][2]) printf("J");
    if (w[1][2] >= w[1][0] && w[1][2] >= w[1][1])      printf(" B");
    else if (w[1][0] >= w[1][1] && w[1][0] >= w[1][2]) printf(" C");
    else if (w[1][1] >= w[1][0] && w[1][1] >= w[1][2]) printf(" J");
    return 0;
}
