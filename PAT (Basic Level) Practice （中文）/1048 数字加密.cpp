#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() > b.size()) 
        b.append(a.size() - b.size(), '0');
    else  
        a.append(b.size() - a.size(), '0');

    string c;
    int temp;
    int len = a.size();
    char str[14] = { "0123456789JQK" };
    for (int i = 0; i < len; ++i)
    {
        if ((i + 1) % 2 == 0)
        {
            temp = b[i] - a[i];
            if (temp < 0) temp += 10;
            c += str[temp];
        }
        else
        {
            c += str[(b[i] - '0' + a[i] - '0') % 13];
        }
    }

    for (int i = c.length() - 1; i >= 0; --i)
        printf("%c", c[i]);
    
    return 0;
}


