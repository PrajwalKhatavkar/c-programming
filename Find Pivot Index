#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0;
    int leftSum = 0;

    // Calculate total sum
    for (int i = 0; i < numsSize; ++i) {
        totalSum += nums[i];
    }

    // Iterate again to find pivot index
    for (int i = 0; i < numsSize; ++i) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    int nums1[] = {1, 7, 3, 6, 5, 6};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output for nums1: %d\n", pivotIndex(nums1, numsSize1));

    int nums2[] = {1, 2, 3};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output for nums2: %d\n", pivotIndex(nums2, numsSize2));

    int nums3[] = {2, 1, -1};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output for nums3: %d\n", pivotIndex(nums3, numsSize3));

    return 
