#include <iostream>
using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) printf("%c", c); printf("\n"); 

    int row = n / 2 - 2;
    if (n % 2 != 0) row += 1;
    for (int i = 0; i < row; ++i) {
        printf("%c", c);
        for(int j = 0; j < n - 2; ++j) printf(" ");
        printf("%c", c);
        printf("\n");
    }
    for (int i = 0; i < n; ++i) printf("%c", c);
    return 0;
}
