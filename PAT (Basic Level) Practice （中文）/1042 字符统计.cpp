#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    string a;
    getline(cin, a);
    map<char, int> um;
    int max_time = 0;
    for (auto& c : a) {
        if (isalpha(c)) {
            ++um[tolower(c)];
            max_time = max(max_time, um[tolower(c)]);
        }
    }
    for (auto& i : um) {
        if (i.second == max_time) {
            cout << i.first << " " << max_time;
            break;
        }
    }
    return 0;
}
