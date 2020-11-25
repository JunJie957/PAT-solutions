#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int, int> p;
int main() {
    int head, n, adr, data, next;
    scanf("%d%d", &n, &head);

    vector<p> arr;
    unordered_map<int, p> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &adr, &data, &next);
        um[adr] = { data, next };
    }
    
    while (head != -1) {
        arr.push_back({ head, um[head].first });
        head = um[head].second;
    }

    sort(arr.begin(), arr.end(), [](p& p1, p& p2) {
        return p1.second < p2.second;
        });
    
    if (!arr.empty()) {
        printf("%d %05d\n", arr.size(), arr[0].first);
        for (int i = 0; i < arr.size() - 1; ++i) {
            printf("%05d %d %05d\n", arr[i].first, arr[i].second, arr[i + 1].first);
        }
        printf("%05d %d -1", arr.back().first, arr.back().second);
    } else {
        printf("0 -1");
    }
 	return 0;
}
