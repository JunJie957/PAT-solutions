#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct people
{
    string name;
    int height;

    bool operator<(const people& p) const
    {
        if (this->height != p.height)
            return this->height < p.height;
        else
            return this->name > p.name;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    int sigle = floor(n / k);
    vector<people> v;
    people tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp.name >> tmp.height;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
   
    vector<vector<people>> res(k);
    for (int i = 0; i < k; ++i)
    {
        res[i].resize(sigle);
    }
    res[k - 1].resize(2 * sigle);

    int mid = floor(sigle / 2) + 1;
    int len = v.size();
    int line = 0;
    int loc = 0;
    int count = 0;
    int count_end = 0;
    for (int i = 0; i < len;)
    {
        if (len - i >= 2 * sigle)
        {
            loc = mid - 1;
            for (int j = sigle - 1; j >= 0; --j)
            {
                res[line][loc] = v[i + j];
                if (count % 2 == 0)
                {
                    loc -= (count + 1);
                    ++count;
                }
                else
                {
                    loc += (count + 1);
                    ++count;
                }
            }
            ++line;
            count = 0;
            i += sigle;
        }
        else
        {
            count_end = len - i;
            loc = floor(count_end / 2) + 1 - 1;
            count = 0;
            for (int j = len - i -1; j >= 0; --j)
            {
                res[line][loc] = v[i + j];
                if (count % 2 == 0)
                {
                    loc -= (count + 1);
                    ++count;
                }
                else
                {
                    loc += (count + 1);
                    ++count;
                }
            }
            i += len - i;
        }
    }

    // 输出最后一行
    for (int j = 0; j < count_end; ++j)
    {
        if (j != 0) printf(" ");
        printf("%s", res[k - 1][j].name.c_str());
    }

    // 输出其余行，按行倒序输出
    for (int i = k - 2; i >= 0; --i)
    {
        cout << endl;
        for (int j = 0; j < sigle; ++j)
        {
            if (j != 0) printf(" ");
            printf("%s", res[i][j].name.c_str());
        }
    }

    return 0;
}


