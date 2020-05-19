#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int n, d;
    double e, use;
    cin >> n >> e >> d;

    int maybe_empty = 0, empty = 0, count_elec = 0, k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> use;
            if (use < e) count_elec++;
        }

        if (count_elec > k / 2)
        {
            if (k > d) empty++;
            else maybe_empty++;
        }
        count_elec = 0;
    }

    printf("%0.1lf%% %0.1lf%%", (double)maybe_empty / n * 100, (double)empty / n * 100);
    
    return 0;
}


