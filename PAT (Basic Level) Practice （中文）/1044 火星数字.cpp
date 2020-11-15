#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> s1{
    "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct","nov", "dec"
};

vector<string> s2{
    "tam", "hel", "maa", "huh", "tou", "kes", "hei","elo", "syy", "lok", "mer", "jou"
};

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    string temp;
    for (int j = 0; j < n; ++j) {
        getline(cin, temp);

        // 数字转为火星文
        if (temp[0] >= '0' && temp[0] <= '9') {
            int num = stoi(temp);
            if (num >= 13 && num % 13 == 0)
            {
                cout << s2[num / 13 - 1] << endl;
            }
            else
            {
                if (num >= 13) 
                {
                    cout << s2[num / 13 - 1] << " ";
                }
                cout << s1[num % 13] << endl;
            }
        }
        else {
            // 火星文转为数字
            if (temp.size() == 3) {
                for (int i = 0; i < 13; ++i) {
                    if (temp.compare(s1[i]) == 0) {
                        cout << i << endl;
                        break;
                    }

                    if (temp.compare(s2[i]) == 0) {
                        cout << (i + 1) * 13 << endl;
                        break;
                    }
                }
            }
            else if (temp.size() == 4)
            {
                cout << "0" << endl;
            }
            else{
                int num = 0;
                for (int i = 0; i < 12; ++i) {
                    if (temp.substr(0,3).compare(s2[i]) == 0) {
                        num = (i + 1) * 13;
                        break;
                    }
                }

                for (int i = 0; i < 13; ++i) {
                    if (temp.substr(4,3).compare(s1[i]) == 0) {
                        num += i;
                        break;
                    }
                }
                cout << num << endl;
            }
        }
    }
    return 0;
}
