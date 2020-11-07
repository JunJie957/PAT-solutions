#include <iostream>
using namespace std;
int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int i = 0; i < n; ++i) printf("%c", c); printf("\n"); 
    for (int i = 0; i < (n + 1) / 2 - 2; ++i) {
        printf("%c", c);
        for (int j = 1; j < n - 1; ++j) printf(" ");
        printf("%c\n", c);
    }
    for (int i = 0; i < n; ++i) printf("%c", c); 
    return 0;
}
