#include <iostream>
using namespace std;
int main() {
    long int c1, c2;
    scanf("%ld%ld", &c1, &c2);
    c2 = (c2 - c1) / 100.0 + 0.5;
    printf("%02d:%02d:%02d", c2 / 3600, c2 % 3600 / 60, c2 % 3600 % 60);
    return 0;
}
