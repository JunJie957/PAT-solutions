#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> vmax;
vector<int> vmin;

int main() 
{
    int n;
    cin >> n;
    
    int temp;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &temp);
        v.push_back(temp);
    }

    // vmax: 用来记录左侧区域的最大值，i需要大于左侧区域的最大值
    int left_max = -1;
    vmax.push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        if (left_max < v[i]) left_max = v[i];
        vmax.push_back(left_max);
    }

    // vmin: 用来记录右侧区域的最小值，i需要小于右侧区域的最小值
    int right_min = v[n - 1];
    vmin.push_back(v[n - 1] + 1);
    for (int i = n - 1; i >= 0; --i)
    {
        if (right_min > v[i]) right_min = v[i];
        vmin.push_back(right_min);
    }

    // 比较，计数过程，使用set自动排序
    int count = 0;
    set<int> res;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > vmax[i] && v[i] < vmin[n- 1 -i])
        {
            count++;
            res.insert(v[i]);
        }
    }
    
    // 输出总数
    cout << count << endl;

    // 从小到大输出结果，注意最后要加一个换行符，当 count = 0时，第二行要为空
    for (auto iter = res.begin(); iter != res.end(); ++iter)
    {
        if (iter != res.begin()) printf(" ");
        printf("%d", *iter);
    }
    printf("\n");

    return 0;
}


