#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<char> v(3), word{ 'W','T','L' };
    double num, tmp = 0.0, res = 1.0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &num);
            if (num > tmp) {
                tmp = num;
                v[i] = word[j];
            }
        }
        res *= tmp;
        tmp = 0.0;
    }
    res = (res * 0.65 - 1) * 2;
    printf("%c %c %c %0.2lf", v[0], v[1], v[2], res);
    return 0;
}
