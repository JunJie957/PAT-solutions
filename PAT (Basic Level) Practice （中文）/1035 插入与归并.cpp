#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[100], b[100], i, j;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; ++i);
    for (j = i + 1; a[j] == b[j] && j < n; ++j);

    // ���ǰ�����򣬺���������Ϊ�������򣬷���Ϊ�鲢����
    // ������������������ԭ���еĶ�Ӧ��������ͬ�ģ�û�о����ƶ���
    if (j == n) {
        printf("Insertion Sort\n");
        sort(a, a + i + 1 + 1); // ��������Ϊ [0, i + 1], ����[0, i + 1 + 1], ����һλ
    } else {
        printf("Merge Sort\n");
        int k = 1, flag = 1;
        while (flag) {
            flag = 0;
            for (i = 0; i < n; ++i) {
                if (a[i] != b[i]) flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; ++i)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + n / k * k, a + n);
        }
    }
    printf("%d", a[0]);
    for (j = 1; j < n; ++j) printf(" %d", a[j]);
    return 0;
}
