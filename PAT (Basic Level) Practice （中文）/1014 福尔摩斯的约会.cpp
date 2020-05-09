#include <iostream>
#include <cctype>
using namespace std;

int main() 
{
    int i = 0;
    int j = 0;
    string a, b, c, d;
    string week[7] = { "MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN " };

    cin >> a >> b >> c >> d;

    while (a.length() > i && b.length() > i)
    {
        if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G')
        {
            cout << week[a[i] - 'A'];
            break;
        }
        ++i;
    }

    ++i;
    while (a.length() > i && b.length() > i)
    {
        if (a[i] == b[i])
        {
            if (a[i] >= 'A' && a[i] <= 'N')
            {
                cout << a[i] - 'A' + 10 << ":";
                break;
            }
            else if (a[i] >= '0' && a[i] <= '9')
            {
                printf("%02d:", a[i] - '0');
                break;
            }
        }
        ++i;
    }

    while (c.length() > j && d.length() > j)
    {
        if (isalpha(c[j]) && c[j] == d[j])
            printf("%02d", j);
        j++;
    }

    return 0;
}
