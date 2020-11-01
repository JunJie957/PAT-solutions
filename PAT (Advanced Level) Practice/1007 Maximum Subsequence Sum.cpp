#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    vector<int> nums(k, 0);
    int sum = -1, tmpSum = 0, pos = 0, left = 0, right = k - 1;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &nums[i]);
        tmpSum += nums[i];
        if (tmpSum < 0) {
            tmpSum = 0;
            pos = i + 1;
        } else if(tmpSum > sum) {
            sum = tmpSum;
            left = pos;
            right = i;
        }
    }
    printf("%d %d %d", sum < 0 ? 0 : sum, nums[left], nums[right]);
    return 0;
}
