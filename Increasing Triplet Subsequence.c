#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    int min = INT_MAX, secondMin = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= min) {
            min = nums[i];
        } else if (nums[i] <= secondMin) {
            secondMin = nums[i];
        } else {
            return true;
        }
    }
    
    return false;
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %s\n", increasingTriplet(nums1, numsSize1) ? "true" : "false");

    int nums2[] = {5, 4, 3, 2, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: %s\n", increasingTriplet(nums2, numsSize2) ? "true" : "false");
    
    int nums3[] = {2, 1, 5, 0, 4, 6};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Example 3: %s\n", increasingTriplet(nums3, numsSize3) ? "true" : "false");
    
    return 0;
}
