#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> um;
    int n, school, score, maxSchool = 1, maxScore = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &school, &score);
        um[school] += score;
        if (um[school] > maxScore) {
            maxScore = um[school];
            maxSchool = school;
        }
    }
    printf("%d %d", maxSchool, maxScore);
    return 0;
}
