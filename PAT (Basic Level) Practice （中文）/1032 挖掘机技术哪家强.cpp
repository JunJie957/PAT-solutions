#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n, num, score, school = 1, max_score = 0;
    scanf("%d", &n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &num, &score);
        if ((um[num] += score) > max_score) {
            school = num;
            max_score = um[num];
        }
    }
    printf("%d %d", school, max_score);
    return 0;
}
