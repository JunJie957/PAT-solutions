#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    unordered_map<int, int> m;
    unordered_map<int, int>::iterator iter;
    int team_num, player_num, score;

    for (int i = 0; i < n; ++i)
    {
        scanf("%d-%d %d", &team_num, &player_num, &score);
        iter = m.find(team_num);
       
        if (iter != m.end()) iter->second += score;
        else  m.insert(pair<int, int>(team_num, score));
    }

    int max = -1, number = -1;
    for (iter = m.begin(); iter != m.end(); ++iter)
    {
        if (iter->second > max)
        {
            max = iter->second;
            number = iter->first;
        }
    }
    cout << number << " " << max;
   
    return 0;
}


