#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() 
{
    string str;
    cin >> str;
 
    int count_P = 0, count_A = 0, count_T = 0, count_e = 0, count_s = 0, count_t = 0;
    unsigned int len = str.size();
    for (unsigned int i = 0; i < str.size(); ++i)
    {
        switch (str[i])
        {
            case 'P':
                count_P++;
                break;
            case 'A':
                count_A++;
                break;
            case 'T':
                count_T++;
                break;
            case 'e':
                count_e++;
                break;
            case 's':
                count_s++;
                break;
            case 't':
                count_t++;
                break;
            default:
                break;
        }
    }
 
 
    while (count_P > 0 || count_A > 0 || count_T > 0 || count_e > 0 || count_s > 0 || count_t > 0)
    {
        if (count_P-- > 0)  printf("P");
        if (count_A-- > 0)  printf("A");
        if (count_T-- > 0)  printf("T");
        if (count_e-- > 0)  printf("e");
        if (count_s-- > 0)  printf("s");
        if (count_t-- > 0)  printf("t");
    }
    return 0;
}


