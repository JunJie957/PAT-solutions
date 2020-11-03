#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    string str, tmp;
    getline(cin, str);
    
    stack<string> res;
    for (auto& iter : str) {
        if (iter != ' ') tmp += iter;
        else {
            res.emplace(tmp);
            tmp.clear();
        }
    }
    if(!tmp.empty()) res.emplace(tmp);
    
    cout << res.top(); res.pop();
    while (!res.empty()) {
        cout << " " << res.top();
        res.pop();
    }
    return 0;
}
