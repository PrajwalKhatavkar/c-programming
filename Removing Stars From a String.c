#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeStars(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n * sizeof(char)); // Stack to store characters
    int top = -1; // Index of the top element in the stack

    // Iterate through the string from left to right
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            if (top >= 0) {
                // If there are characters in the stack, remove the top character
                top--;
            }
        } else {
            // Push non-star characters onto the stack
            stack[++top] = s[i];
        }
    }

    // Null-terminate the string
    stack[top + 1] = '\0';
    return stack;
}

int main() {
    char s1[] = "leet**cod*e";
    printf("Output for s1: %s\n", removeStars(s1));

    char s2[] = "erase*****";
    printf("Output for s2: %s\n", removeStars(s2));

    return 0;
}
