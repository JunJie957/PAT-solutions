#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main() {
    int head, n, adr, data, next;
    scanf("%d%d", &head, &n);
    unordered_map<int, pair<int, int>> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &adr, &data, &next);
        um[adr] = { data, next };
    }

    unordered_set<int> us;
    vector<pair<int, int>> only, appear;
    while (head != -1) {
        auto i = make_pair(head, um[head].first);
        if (us.count(abs(um[head].first))) {
            appear.emplace_back(i);
        } else {
            only.emplace_back(i);
            us.emplace(abs(um[head].first));
        }
        head = um[head].second;
    }

    for (int i = 0; i < only.size() - 1; ++i) {
        printf("%05d %d %05d\n", only[i].first, only[i].second, only[i + 1].first);
    }
    printf("%05d %d -1\n", only.back().first, only.back().second);

    if (!appear.empty()) {
        for (int i = 0; i < appear.size() - 1; ++i) {
            printf("%05d %d %05d\n", appear[i].first, appear[i].second, appear[i + 1].first);
        }
        printf("%05d %d -1\n", appear.back().first, appear.back().second);
    }
    return 0;
}
