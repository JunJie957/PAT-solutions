#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> lists{
    "S1","S2","S3","S4","S5","S6","S7", "S8","S9","S10","S11","S12","S13",
    "H1","H2","H3","H4","H5","H6","H7", "H8","H9","H10","H11","H12","H13",
    "C1","C2","C3","C4","C5","C6","C7", "C8","C9","C10","C11","C12","C13",
    "D1","D2","D3","D4","D5","D6","D7", "D8","D9","D10","D11","D12","D13",
    "J1","J2",
};

int main() {
    vector<int> nums;
    for (int i = 1; i <= 54; ++i) nums.emplace_back(i);

    int k;
    scanf("%d", &k);
    vector<int> order(54, 0);
    for (int i = 0; i < 54; ++i) scanf("%d", &order[i]);
    
    for (int i = 0; i < k; ++i) {
        vector<int> temp(54, 0);
        for (int j = 0; j < 54; ++j) temp[order[j] - 1] = nums[j];
        nums = temp;
    }

    cout << lists[nums[0] - 1];
    for (int i = 1; i < 54; ++i) cout << " " << lists[nums[i] - 1];
    return 0;
}
