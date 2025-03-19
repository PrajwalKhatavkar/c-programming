#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int nonZeroPos = 0;
    
    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        // If the current element is non-zero, swap it with the element at nonZeroPos
        if (nums[i] != 0) {
            int temp = nums[nonZeroPos];
            nums[nonZeroPos] = nums[i];
            nums[i] = temp;
            nonZeroPos++;
        }
    }
}

int main() {
    int nums1[] = {0, 1, 0, 3, 12};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    
    moveZeroes(nums1, numsSize1);
    
    printf("Example 1: [");
    for (int i = 0; i < numsSize1; i++) {
        printf("%d", nums1[i]);
        if (i < numsSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    int nums2[] = {0};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    
    moveZeroes(nums2, numsSize2);
    
    printf("Example 2: [");
    for (int i = 0; i < numsSize2; i++) {
        printf("%d", nums2[i]);
        if (i < numsSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    return 0;
}
