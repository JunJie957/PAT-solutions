#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n, team, number, score, max_score = 0, max_id = 0;
    scanf("%d", &n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d-%d%d", &team, &number, &score);
        um[team] += score;
        if (max_score < um[team]) {
            max_id = team;
            max_score = um[team];
        }
    }
    printf("%d %d", max_id, um[max_id]);
    return 0;
}
