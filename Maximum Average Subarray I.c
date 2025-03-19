#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    int sum = 0;
    // Calculate the sum of the first k elements
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    double max_avg = (double) sum / k;

    // Slide the window and update the sum
    for (int i = k; i < numsSize; ++i) {
        sum += nums[i] - nums[i - k]; // slide the window by adding the next element and removing the first element
        double avg = (double) sum / k;
        if (avg > max_avg) {
            max_avg = avg;
        }
    }
    return max_avg;
}

int main() {
    int nums1[] = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output for nums1: %.5lf\n", findMaxAverage(nums1, numsSize1, k1));

    int nums2[] = {5};
    int k2 = 1;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output for nums2: %.5lf\n", findMaxAverage(nums2, numsSize2, k2));

    return 0;
}
