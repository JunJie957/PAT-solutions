#include <iostream>
using namespace std;
int main() {
    int n, min_score = 101, max_score = -1, score;
    scanf("%d", &n);
    string name, num, min_name, min_num, max_name, max_num;
    for (int i = 0; i < n; ++i) {
        cin >> name >> num >> score;
        if (score > max_score) {
            max_num = num;
            max_name = name;
            max_score = score;
        }
        if (score < min_score) {
            min_num = num;
            min_name = name;
            min_score = score;
        }
    }
    cout << max_name << " " << max_num << endl << min_name << " " << min_num;
    return 0;
}
