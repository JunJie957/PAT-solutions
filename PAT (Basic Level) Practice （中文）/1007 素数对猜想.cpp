#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int n) {
    int sqr = sqrt(n);
    for (int i = 2; i <= sqr; ++i) 
        if (n % i == 0) return false;
    return true;
} 
int main() {
    int n;
    scanf("%d", &n);
    vector<int> ans;
    vector<bool> flag(n + 1, true);
    for (int i = 3; i <= n; ++i) {
        if (flag[i] == false) continue;
        if (isPrime(i)) {
            ans.emplace_back(i);
        } else {
            flag[i] = false;
        }
        int j = i + i;
        while (j <= n) {
            flag[j] = false;
            j += i;
        }
    }
    int cnt = 0;
    for (int i = ans.size() - 1; i > 0; --i) {
        if (ans[i] - ans[i - 1] == 2) ++cnt;
    }
    cout << cnt;
    return 0;
}
