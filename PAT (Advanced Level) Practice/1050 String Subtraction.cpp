#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    unordered_set<char> uc;
    for (auto& iter : b) uc.emplace(iter);
    for (auto& iter : a) if (uc.count(iter) == 0) c += iter;
    cout << c;
    return 0;
}
