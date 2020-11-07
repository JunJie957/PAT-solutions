#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, grade, max_f = -1, min_m = 101, f_g, m_g;
    scanf("%d", &n);
    string name, gender, id, f_name, f_id, m_name, m_id;
    for (int i = 0; i < n; ++i) {
        cin >> name >> gender >> id >> grade;
        if (gender == "F" && grade > max_f) {
            max_f = grade; f_name = name; f_id = id; f_g = grade;
        }
        if (gender == "M" && grade < min_m) {
            min_m = grade; m_name = name; m_id = id; m_g = grade;
        }
    }
    if (max_f != -1) printf("%s %s\n", f_name.c_str(), f_id.c_str());
    else printf("Absent\n");
    if (min_m != 101) printf("%s %s\n", m_name.c_str(), m_id.c_str());
    else printf("Absent\n");
    if (max_f != -1 && min_m != 101) printf("%d", f_g - m_g);
    else printf("NA");
    return 0;
}
