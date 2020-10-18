#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N, m, n, t = 0;
    scanf("%d", &N);

    // �ҵ� m �� n ��ֵ
    for (n = sqrt(double(N)); n > 0; --n) {
        if (N % n == 0) {
            m = N / n;
            break;
        }
    }

    vector<int> a(N, 0);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    sort(a.begin(), a.end(), greater<int>());

    // m �� n ��
    vector<vector<int>> b(m, vector<int>(n));
    int level = m / 2 + m % 2; 
    for (int i = 0; i < level; ++i) {
        for (int j = i; j <= n - 1 - i && t <= N - 1; ++j)
            b[i][j] = a[t++]; // ��һ��
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; ++j)
            b[j][n - 1 - i] = a[t++]; // ���һ��
        for (int j = n - i - 1; j >= i && t <= N - 1; --j)
            b[m - 1 - i][j] = a[t++]; // ���һ��
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; --j)
            b[j][i] = a[t++]; // ��һ��
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", b[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
