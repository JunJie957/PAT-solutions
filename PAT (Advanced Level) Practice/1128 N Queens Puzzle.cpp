#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n, loc, flag = 1;
    vector<int> nums;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &n);
        nums.resize(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &loc);
            if (flag) {
                nums[j] = loc;
                for (int m = 0; m < j; ++m) {
                    if (nums[j] == nums[m] || abs(nums[j] - nums[m]) == abs(j - m)) {
                        printf("NO\n"); 
                        flag = 0; 
                        nums.clear(); 
                        break;
                    }
                }
           }
        }
        if (flag) printf("YES\n");
        flag = 1;
    }
    return 0;
}
