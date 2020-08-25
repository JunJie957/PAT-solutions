#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<string> machine {
    " ",
    "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
    "J1", "J2"
};

int main()
{
    int k, number;
    scanf("%d", &k);
    vector<int> v;
    for (int i = 0; i < 54; ++i) {
        scanf("%d", &number);
        v.push_back(number);
    }

    vector<string> machine_bk(machine.size(), "");
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 54; ++j) {
            machine_bk[v[j]] = machine[j + 1];
        }
        if(i != k - 1) machine = machine_bk;
    }

    printf("%s", machine_bk[1].c_str());
    for (int i = 2; i < 55; ++i) {
        printf(" %s", machine_bk[i].c_str());
    }
    return 0;
}
