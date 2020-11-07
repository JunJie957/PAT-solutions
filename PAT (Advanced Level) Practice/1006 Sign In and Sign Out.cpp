#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string id, in, out, id_in, id_out, signin = "23:59:59", signout = "00:00:00";
    scanf("%d", &n);
    while(n--) {
        cin >> id >> in >> out;
        if (in < signin) {
            signin = in;
            id_in = id;
        }
        if (out > signout) {
            signout = out;
            id_out = id;
        }
    }
    cout << id_in << " " << id_out;
    return 0;
}
