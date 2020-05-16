#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

char str[1001] = { 0 };

int main() 
{
    cin.getline(str, std::streamsize(1001));

    int len = strlen(str);
    vector<int> count(26, 0);
    for (int i = 0; i < len; ++i)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            count[toupper(str[i]) - 'A']++;
    }

    char c = 'a';
    int max = count[0];
    for (int i = 1; i < 26; ++i)
    {
        if (count[i] > max)
        {
            max = count[i];
            c = 'a' + i;
        }
    }
    cout << c << " " << max;

    return 0;
}


