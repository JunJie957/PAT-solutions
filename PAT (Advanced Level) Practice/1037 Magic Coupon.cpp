#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    scanf("%d", &n);
    vector<int> copy(n);
    for (int i = 0; i < n; ++i) scanf("%d", &copy[i]);
    scanf("%d", &m);
    vector<int> product(m);
    for (int i = 0; i < m; ++i) scanf("%d", &product[i]);
    sort(copy.begin(), copy.end(), [](int& v1, int& v2) {return v1 > v2; });
    sort(product.begin(), product.end(), [](int& v1, int& v2) {return v1 > v2; });
    int loc = 0, res = 0;
    for (auto& iter : product) {
        if (copy[loc] > 0 && iter > 0) res += iter * copy[loc++];
    }
    loc = n - 1;
    for (int i = m - 1; i >= 0; --i) {
        if (copy[loc] < 0 && product[i] < 0) res += product[i] * copy[loc--];
    }
    printf("%d", res);
    return 0;
}
