#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool isdigits(const string& str)
{
    int len = str.size();
    if (len > 0)
    {
        if (str[0] == '-')
        {
            if (!(str[1] >= '0' && str[1] <= '9')) return false;
            if (len >= 3 && str[1] == '0' && str[2] != '.') return false;
        }
        else
        {
            if (!(str[0] >= '0' && str[0] <= '9'))  return false;
            if (len >= 2 && str[0] == '0' && str[1] != '.') return false;
        }
        
        for (int i = 1; i < len; ++i)
        {
            if (str[i] == '.')
            {
                if (str[0] != '-' && len - i - 1 > 2) return false;
                else if(str[0] == '-' && len - i - 2 > 2) return false;
            }
            else if (!(str[i] >= '0' && str[i] <= '9')) return false;
        }

        if (atof(str.c_str()) > 1000 || atof(str.c_str()) < -1000)  
            return false;
        return true;
    }
    return false;
}

int main()
{
    string str;
    double sum = 0;
    int n, len, count = 0;;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        if (!isdigits(str))
        {
            cout << "ERROR: " << str << " is not a legal number" << endl;
        }
        else
        {
            sum += atof(str.c_str());
            count++;
        }
    }

    if (count > 1)
        printf("The average of %d numbers is %.2f", count, sum / count);
    else if(count == 1)
        printf("The average of 1 number is %.2f", sum / count);
    else
        printf("The average of 0 numbers is Undefined");

    return 0;
}


