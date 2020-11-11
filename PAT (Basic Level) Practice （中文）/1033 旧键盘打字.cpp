#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    unordered_set<char> us;
    for (auto& iter : a) {
        us.emplace(iter);
        if (isupper(iter)) us.emplace(tolower(iter)); // Ìí¼ÓĞ¡Ğ´×ÖÄ¸
        if (iter == '+') for (int i = 0; i < 26; ++i) us.emplace('A' + i);
    }
    bool flag = false;
    for (auto& iter : b) {
        if (us.find(iter) == us.end()) {
            printf("%c", iter);
            flag = true;
        }
    }
    if (!flag) printf("\n");
    return 0;
}
