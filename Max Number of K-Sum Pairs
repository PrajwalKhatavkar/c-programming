#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int maxOperations(int* nums, int numsSize, int k) {
    int hash[MAX_SIZE + 1] = {0};
    int operations = 0;

    // Count the frequency of each number
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = k - nums[i];
        if (complement > MAX_SIZE || complement < 0 || hash[complement] <= 0) {
            continue; // Complement not found or exceeds array size
        }
        // Remove both nums[i] and complement
        hash[nums[i]]--;
        hash[complement]--;
        operations++;
    }

    return operations;
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int k1 = 5;
    printf("Example 1: %d\n", maxOperations(nums1, sizeof(nums1) / sizeof(nums1[0]), k1));

    int nums2[] = {3, 1, 3, 4, 3};
    int k2 = 6;
    printf("Example 2: %d\n", maxOperations(nums2, sizeof(nums2) / sizeof(nums2[0]), k2));

    return 0;
}

