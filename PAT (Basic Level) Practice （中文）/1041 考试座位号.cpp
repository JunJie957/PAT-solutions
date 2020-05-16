#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct examinee
{
    string exam_num;
    int loc;
};

int main() 
{
    int n, test_num;
    cin >> n;

    examinee e;
    unordered_map<int, examinee> m;
    for (int i = 0; i < n; ++i)
    {
       cin >> e.exam_num >> test_num >> e.loc;
        m.insert(pair<int, examinee>(test_num, e));
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> test_num;
        auto iter = m.find(test_num);
        if (iter != m.end())
            cout << iter->second.exam_num << " " << iter->second.loc << endl;
    }
    return 0;
}


