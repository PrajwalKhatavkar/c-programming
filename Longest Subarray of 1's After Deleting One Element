#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int left = 0, right;
    int max_length = 0;
    int zero_count = 0;

    for (right = 0; right < numsSize; ++right) {
        if (nums[right] == 0) {
            zero_count++;
        }

        // If the number of zeros in the window exceeds 1, shrink the window from the left side
        while (zero_count > 1) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }

        // Update max_length with the maximum window size
        max_length = (right - left > max_length) ? right - left : max_length;
    }

    // Adding 1 to max_length as we are only allowed to delete one element
    return max_length + 1;
}

int main() {
    int nums1[] = {1, 1, 0, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output for nums1: %d\n", longestSubarray(nums1, numsSize1));

    int nums2[] = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output for nums2: %d\n", longestSubarray(nums2, numsSize2));

    int nums3[] = {1, 1, 1};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output for nums3: %d\n", longestSubarray(nums3, numsSize3));

    return 0;
}
