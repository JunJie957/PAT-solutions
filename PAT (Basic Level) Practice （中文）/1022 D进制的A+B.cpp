#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    long int sum = a + b;
    vector<int> ans;
    do {
        ans.emplace_back(sum % d);
        sum /= d;
    } while (sum != 0);
    for (int i = ans.size() - 1; i >= 0; --i)  printf("%d", ans[i]);
    return 0;
}
