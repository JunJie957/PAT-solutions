#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string tmp1, tmp2;
    unordered_map<string,string> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp1 >> tmp2;
        s.insert(pair<string, string>(tmp1, tmp2));
        s.insert(pair<string, string>(tmp2, tmp1));
    }

    int m, sigle = 0;
    set<string> sigle_guset;
    unordered_map<string,string> another;
    
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp1;
        auto another_find = another.find(tmp1);
        if (another_find != another.end())
        {
            another.erase(tmp1);
            continue;
        }

        auto iter = s.find(tmp1);
        if (iter == s.end())
        {
            sigle++;
            sigle_guset.insert(tmp1);
        }
        else
        {
            another.insert(pair<string, string>(iter->second, tmp1));
        }
    }

   for (auto iter = another.begin(); iter != another.end(); ++iter)
    {
        sigle++;
        sigle_guset.insert(iter->second);
    }

    printf("%d\n", sigle);
    for (auto iter = sigle_guset.begin(); iter != sigle_guset.end(); ++iter)
    {
        if (iter != sigle_guset.begin()) printf(" ");
        printf("%s", (*iter).c_str());
    }

    return 0;
}
