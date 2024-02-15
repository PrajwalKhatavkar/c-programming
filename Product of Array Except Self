#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Calculate the product of all elements to the left of each element
    int leftProduct = 1;
    for (int i = 0; i < numsSize; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // Calculate the product of all elements to the right of each element and multiply it with the left product
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int size1;
    int* result1 = productExceptSelf(nums1, 4, &size1);
    printf("Output for [1, 2, 3, 4]: [");
    for (int i = 0; i < size1; i++) {
        printf("%d", result1[i]);
        if (i < size1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result1);
    
    int nums2[] = {-1, 1, 0, -3, 3};
    int size2;
    int* result2 = productExceptSelf(nums2, 5, &size2);
    printf("Output for [-1, 1, 0, -3, 3]: [");
    for (int i = 0; i < size2; i++) {
        printf("%d", result2[i]);
        if (i < size2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result2);
    
    return 0;
}

