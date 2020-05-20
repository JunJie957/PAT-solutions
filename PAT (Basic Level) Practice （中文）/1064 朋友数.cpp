#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string str;
    map<int, vector<string>> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        
        int sum = 0;
        int len = str.length();
        for (int j = 0; j < len; ++j) sum += (str[j] - '0');

        auto iter = s.find(sum);
        if (iter != s.end()) iter->second.push_back(str);
        else
        {
            vector<string> v2;
            v2.push_back(str);
            s.insert(pair<int, vector<string>>(sum, v2));
        }
    }

    printf("%u\n", s.size());
    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        if (iter != s.begin()) printf(" ");
        printf("%d", iter->first);
    }
    return 0;
}
