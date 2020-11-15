#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n, p = 0, t = 0;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        unordered_map<int, int> um;
        for (int j = 0; j < s.length(); ++j) {
            um[s[j]]++;
            if (s[j] == 'P') p = j;
            if (s[j] == 'T') t = j;
        }
        if (um['P'] == 1 && um['A'] != 0 && um['T'] == 1 && um.size() == 3 && t - p != 1 && p * (t - p - 1) == s.length() - t - 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
