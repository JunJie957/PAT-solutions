#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int m, n, u, v, a;
    scanf("%d%d", &m, &n);
    vector<int> node(n);
    unordered_set<int> us;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&node[i]);
        us.emplace(node[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        for (int j = 0; j < n; ++j) {
            a = node[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }
        if (!us.count(u) && !us.count(v))
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!us.count(u) || !us.count(v))
            printf("ERROR: %d is not found.\n", !us.count(u) ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}
