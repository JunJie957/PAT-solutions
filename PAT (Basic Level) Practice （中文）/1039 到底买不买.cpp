#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    unordered_map<char, int> shop, need;
    for (auto& iter : a) ++shop[iter];
    int missing = 0, extra = 0;
    for (auto& iter : b) {
        if (shop.find(iter) != shop.end()) {
           if(--shop[iter] == 0) shop.erase(iter);
        } else ++missing;
    }
    for (auto& iter : shop) extra += iter.second;
    if (missing == 0) cout << "Yes " << extra;
    else cout << "No " << missing;
    return 0;
}
