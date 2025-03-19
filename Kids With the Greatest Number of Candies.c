#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    // Find the maximum number of candies
    int maxCandies = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }
    
    // Allocate memory for the boolean array
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;
    
    // Check if each kid can have the greatest number of candies
    for (int i = 0; i < candiesSize; i++) {
        result[i] = (candies[i] + extraCandies >= maxCandies);
    }
    
    return result;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = 5;
    int extraCandies = 3;
    int returnSize;
    
    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
    
    printf("Result: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%s", result[i] ? "true" : "false");
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Free the dynamically allocated memory
    free(result);
    
    return 0;
}
