#include <iostream>
#include <vector>
using namespace std;

bool flag = false;
void myPrint(vector<int>& nums, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        if (!flag) {
            flag = true;
            printf("%d", nums[i]);
        } else {
            printf(" %d", nums[i]);
        }
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
