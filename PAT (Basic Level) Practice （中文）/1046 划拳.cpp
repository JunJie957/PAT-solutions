#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() 
{
    int n;
    cin >> n;

    int a, a1, b, b1, sum;// ¼×º° ¼×»® ÒÒº° ÒÒ»®
    int count_a = 0, count_b = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d %d", &a, &a1, &b, &b1);
        sum = a + b;
        if (sum == a1 && sum != b1)  ++count_b;
        else if (sum != a1 && sum == b1) ++count_a;
    }
    cout << count_a << " " << count_b;
    return 0;
}


