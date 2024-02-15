#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapping of digits to letters
const char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Helper function to backtrack and generate letter combinations
void backtrack(char* digits, int index, char* combination, char** result, int* returnSize) {
    // If we have processed all digits, add the combination to the result array
    if (index == strlen(digits)) {
        combination[index] = '\0';
        result[*returnSize] = strdup(combination);
        (*returnSize)++;
        return;
    }
    
    // Get the current digit and its corresponding letters
    int digit = digits[index] - '0';
    const char* letters = mapping[digit];
    
    // Iterate through each letter and recursively backtrack
    for (int i = 0; i < strlen(letters); i++) {
        combination[index] = letters[i];
        backtrack(digits, index + 1, combination, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    // Initialize returnSize
    *returnSize = 0;
    
    // If digits is empty, return an empty array
    if (strlen(digits) == 0) {
        return NULL;
    }
    
    // Calculate the number of possible combinations
    int numCombinations = 1;
    for (int i = 0; i < strlen(digits); i++) {
        int digit = digits[i] - '0';
        numCombinations *= strlen(mapping[digit]);
    }
    
    // Allocate memory for the result array
    char** result = (char**)malloc(numCombinations * sizeof(char*));
    
    // Backtrack to generate all combinations
    char combination[strlen(digits) + 1]; // +1 for the null terminator
    backtrack(digits, 0, combination, result, returnSize);
    
    return result;
}

int main() {
    char digits[] = "23";
    int returnSize;
    char** result = letterCombinations(digits, &returnSize);
    
    // Print the result
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%s", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
        free(result[i]);
    }
    printf("]\n");
    
    // Free memory
    free(result);
    
    return 0;
}
