#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums1[] = {2, 2, 1};
    int nums2[] = {4, 1, 2, 1, 2};
    int nums3[] = {1};

    int single1 = singleNumber(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int single2 = singleNumber(nums2, sizeof(nums2) / sizeof(nums2[0]));
    int single3 = singleNumber(nums3, sizeof(nums3) / sizeof(nums3[0]));

    printf("Output 1: %d\n", single1); // Output: 1
    printf("Output 2: %d\n", single2); // Output: 4
    printf("Output 3: %d\n", single3); // Output: 1

    return 0;
}
