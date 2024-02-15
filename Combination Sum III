#include <stdio.h>
#include <stdlib.h>

void backtrack(int start, int k, int n, int* path, int* pathIndex, int** result, int* returnSize) {
    if (n < 0 || *pathIndex == k) {
        if (n == 0 && *pathIndex == k) {
            result[*returnSize] = (int*)malloc(k * sizeof(int));
            for (int i = 0; i < k; i++) {
                result[*returnSize][i] = path[i];
            }
            (*returnSize)++;
        }
        return;
    }
    
    for (int i = start; i <= 9; i++) {
        path[*pathIndex] = i;
        (*pathIndex)++;
        backtrack(i + 1, k, n - i, path, pathIndex, result, returnSize);
        (*pathIndex)--;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    
    // Allocate memory for result array
    int maxCombinations = 1;
    for (int i = 1; i <= k; i++) {
        maxCombinations *= 9 - i + 1;
    }
    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    
    // Allocate memory for temporary path array
    int path[k];
    int pathIndex = 0;
    
    // Backtrack to generate combinations
    backtrack(1, k, n, path, &pathIndex, result, returnSize);
    
    // Set column sizes
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    
    return result;
}

int main() {
    int k = 3, n = 9;
    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum3(k, n, &returnSize, &returnColumnSizes);
    
    // Print the result
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        free(result[i]);
    }
    printf("]\n");
    
    // Free memory
    free(result);
    free(returnColumnSizes);
    
    return 0;
}
