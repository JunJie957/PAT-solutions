#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    unordered_map<char, int> eva;
    unordered_map<char, int> owner;
    for (auto& iter : b) eva[iter]++;
    for (auto& iter : a) owner[iter]++;

    int missing = 0, buy_extra = 0;;
    for (auto& iter : owner) {
        auto find = eva.find(iter.first);
        if (find != eva.end()) {
            if (find->second <= iter.second) {
                buy_extra += iter.second - find->second;
            } else {
                missing += find->second - iter.second;
            }
        } else {
            buy_extra += iter.second;
        }
        eva.erase(iter.first);
    }
    for (auto& iter : eva) missing += iter.second;

    if (missing) {
        printf("No %d", missing);
    } else {
        printf("Yes %d", buy_extra);
    }
    return 0;
}
