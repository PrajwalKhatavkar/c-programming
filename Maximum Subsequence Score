#include <stdio.h>

// Function to calculate the minimum of an array
int min(int* arr, int size) {
    int min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int max_score = 0;
    
    // Generate all possible subsequences of length k
    for (int i = 0; i < nums1Size - k + 1; i++) {
        for (int j = i + k - 1; j < nums1Size; j++) {
            int score = 0;
            // Calculate the score for the current subsequence
            for (int l = i; l <= j; l++) {
                score += nums1[l];
            }
            score *= min(nums2 + i, k);
            // Update the maximum score if necessary
            if (score > max_score) {
                max_score = score;
            }
        }
    }
    
    return max_score;
}

int main() {
    int nums1[] = {1, 3, 3, 2};
    int nums2[] = {2, 1, 3, 4};
    int k = 3;
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int result = maxScore(nums1, nums1Size, nums2, nums2Size, k);
    printf("%d\n", result); // Output: 12
    
    int nums3[] = {4, 2, 3, 1, 1};
    int nums4[] = {7, 5, 10, 9, 6};
    k = 1;
    nums1Size = sizeof(nums3) / sizeof(nums3[0]);
    nums2Size = sizeof(nums4) / sizeof(nums4[0]);
    result = maxScore(nums3, nums1Size, nums4, nums2Size, k);
    printf("%d\n", result); // Output: 30
    
    return 0;
}
