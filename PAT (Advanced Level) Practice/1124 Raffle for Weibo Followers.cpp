#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
    m -  total number of forwards
    n -  the skip number of winners
    s -  the index of the first winner (the indices start from 1).
*/
int main()
{
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    if (s > m) {
        printf("Keep going...");
        return 0;
    }
   
    int preChoose = s;
    string nickname;
    unordered_set<string> us;
    for (int i = 1; i <= m; ++i) {
        cin >> nickname;
        if (i < s) continue;
        else if ((i - preChoose) % n == 0)
        {
            auto iter = us.find(nickname);
            if (iter == us.end()) {
                printf("%s\n", nickname.c_str());
                us.insert(nickname);
            } else {
                while (++i <= m) 
                {
                    cin >> nickname;
                    auto iter = us.find(nickname);
                    if (iter == us.end()) {
                        printf("%s\n", nickname.c_str());
                        us.insert(nickname);
                        break;
                    }
                }
            }
            preChoose = i;
        }
    }
    return 0;
}
