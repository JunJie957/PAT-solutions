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

    // vmax: ������¼�����������ֵ��i��Ҫ���������������ֵ
    int left_max = -1;
    vmax.push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        if (left_max < v[i]) left_max = v[i];
        vmax.push_back(left_max);
    }

    // vmin: ������¼�Ҳ��������Сֵ��i��ҪС���Ҳ��������Сֵ
    int right_min = v[n - 1];
    vmin.push_back(v[n - 1] + 1);
    for (int i = n - 1; i >= 0; --i)
    {
        if (right_min > v[i]) right_min = v[i];
        vmin.push_back(right_min);
    }

    // �Ƚϣ��������̣�ʹ��set�Զ�����
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
    
    // �������
    cout << count << endl;

    // ��С������������ע�����Ҫ��һ�����з����� count = 0ʱ���ڶ���ҪΪ��
    for (auto iter = res.begin(); iter != res.end(); ++iter)
    {
        if (iter != res.begin()) printf(" ");
        printf("%d", *iter);
    }
    printf("\n");

    return 0;
}


