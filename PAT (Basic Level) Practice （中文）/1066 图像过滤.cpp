#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    // m-���� n-����  (a,b)-����˵㣬 k-ָ���滻�ĻҶ�ֵ
    int m, n, a, b, k;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &k);
    
    int tmp;
    for (int i = 0; i < m; ++i)
    {
        bool flag = false;
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &tmp);

            flag ? printf(" ") : flag = true;
            
            if (tmp >= a && tmp <= b) printf("%03d", k);
            else printf("%03d", tmp);
        }
        printf("\n");
    }
    return 0;
}
