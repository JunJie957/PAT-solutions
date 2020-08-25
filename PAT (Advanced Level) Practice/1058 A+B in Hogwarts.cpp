#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int G1, S1, K1, G2, S2, K2;
    scanf("%d.%d.%d %d.%d.%d", &G1, &S1, &K1, &G2, &S2, &K2);
    printf("%d.%d.%d", G1 + G2 + ((S1 + S2 + (K1 + K2) / 29) / 17), (S1 + S2 + (K1 + K2) / 29) % 17, (K1 + K2) % 29);
    return 0;
}
