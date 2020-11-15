#include <iostream>
#include <vector>
using namespace std;
bool space = false;
void myPrint(vector<int>& nums, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        if (space) printf(" ");
        else space = true;
        printf("%d", nums[i]);
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    myPrint(nums, n - (m % n), n);
    myPrint(nums, 0, n - (m % n));
    return 0;
}
