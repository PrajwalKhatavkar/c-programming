dp[i] = max(dp[i-1], dp[i-2] + nums[i])
int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);
    
    for (int i = 2; i < numsSize; i++) {
        dp[i] = fmax(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[numsSize - 1];
}
#include <stdio.h>

int main() {
    int nums1[] = {1, 2, 3, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Maximum amount of money: %d\n", rob(nums1, numsSize1));

    int nums2[] = {2, 7, 9, 3, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Maximum amount of money: %d\n", rob(nums2, numsSize2));
    
    return 0;
}
