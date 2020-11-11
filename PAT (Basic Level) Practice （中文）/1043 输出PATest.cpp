#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    string a;
    getline(cin, a);
    unordered_map<char, int> um;
    for (auto& c : a) ++um[c];
    while (1) {
        bool flag = false;
        if (um['P']-- > 0) { cout << 'P';  flag = true; }
        if (um['A']-- > 0) { cout << 'A';  flag = true; }
        if (um['T']-- > 0) { cout << 'T';  flag = true; }
        if (um['e']-- > 0) { cout << 'e';  flag = true; }
        if (um['s']-- > 0) { cout << 's';  flag = true; }
        if (um['t']-- > 0) { cout << 't';  flag = true; }
        if (!flag) break;
    }
    return 0;
}
