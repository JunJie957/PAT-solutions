#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct QuestionInfo
{
    int score;
    bool ans;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<QuestionInfo> v(m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &v[i].score);
    for (int i = 0; i < m; ++i)
        scanf("%d", &v[i].ans);

    int temp_answer,sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &temp_answer);
            if (temp_answer == v[j].ans)
                sum += v[j].score;
        }
        cout << sum << endl;
    }

    return 0;
}


