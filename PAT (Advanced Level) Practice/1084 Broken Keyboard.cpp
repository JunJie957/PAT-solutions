#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    unordered_set<char> us, loss;

    for (auto& iter : b) 
        us.insert(iter);

    for (auto& iter : a) {
        if (us.find(iter) == us.end()) {
            if (loss.find(iter) == loss.end()) {
                loss.insert(iter);
                if (iter >= 'a' && iter <= 'z') {
                    loss.insert(toupper(iter));
                    printf("%c", toupper(iter));
                } else if (iter >= 'A' && iter <= 'Z') {
                    loss.insert(tolower(iter));
                    printf("%c", iter);
                } else {
                    printf("%c", iter);
                }
            }
        }
    }
    return 0;
}
