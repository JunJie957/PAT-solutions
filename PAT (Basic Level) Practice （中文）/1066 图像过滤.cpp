#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    // m-行数 n-列数  (a,b)-区间端点， k-指定替换的灰度值
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
