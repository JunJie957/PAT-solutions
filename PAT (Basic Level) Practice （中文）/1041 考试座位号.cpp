#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    string str;
    int n, m, x, y;
    unordered_map<int, pair<string, int>> um;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> str >> x >> y;
        um[x] = make_pair(str, y);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        printf("%s %d\n", um[x].first.c_str(), um[x].second);
    }
    return 0;
}
