#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    // Initialize variables
    int* answer = (int*)malloc(temperaturesSize * sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;
    
    // Traverse the temperatures array
    for (int i = 0; i < temperaturesSize; i++) {
        // While the stack is not empty and the current temperature is warmer
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            // Update the answer for the index at the top of the stack
            answer[stack[top]] = i - stack[top];
            // Pop the index from the stack
            top--;
        }
        // Push the current index onto the stack
        stack[++top] = i;
    }
    
    // Update the answer for the remaining indices in the stack
    while (top >= 0) {
        answer[stack[top--]] = 0;
    }
    
    // Set the return size
    *returnSize = temperaturesSize;
    
    // Free the stack
    free(stack);
    
    return answer;
}
