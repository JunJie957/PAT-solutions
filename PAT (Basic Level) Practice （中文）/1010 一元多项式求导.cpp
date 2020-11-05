#include <iostream>
using namespace std;
int main() {
    int n, m;
    bool flag = true;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n * m != 0) {
            if (flag) {
                printf("%d %d", n * m, m - 1);
                flag = false;
            } else {
                printf(" %d %d", n * m, m - 1);
            }
        }
    }
    if (flag) printf("0 0");
    return 0;
}
