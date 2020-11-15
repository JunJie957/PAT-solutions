#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums(10, 0);
    for (int i = 0; i < 10; ++i) scanf("%d", &nums[i]);
    for (int i = 1; i < 10; ++i) {
        if (nums[i] > 0) {
            printf("%d", i);  
            --nums[i];
            break;
        }
    }
    for (int i = 0; i < 10; ++i) while (nums[i]-- > 0) printf("%d", i);  
    return 0;
}
