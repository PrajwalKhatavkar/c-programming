#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decodeString(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc((n + 1) * sizeof(char)); // Stack to keep track of characters
    int top = -1; // Index of the top element in the stack
    int count = 0; // Variable to keep track of the number encountered
    char* decodedString = (char*)malloc((n + 1) * sizeof(char)); // Decoded string
    int decodedIndex = 0; // Index to track the next position to insert characters in the decoded string
    
    for (int i = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            // Digit encountered, update count
            count = count * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            // Opening square bracket encountered, push count onto stack
            stack[++top] = count;
            count = 0; // Reset count
            stack[++top] = '['; // Push '[' onto stack
        } else if (s[i] == ']') {
            // Closing square bracket encountered, start decoding
            char temp[100]; // Temporary array to store decoded string inside brackets
            int tempIndex = 0; // Index to track the next position to insert characters in temp
            
            // Pop characters until '[' is encountered
            while (stack[top] != '[') {
                temp[tempIndex++] = stack[top--];
            }
            top--; // Pop '[' from stack
            
            // Pop count from stack
            int repeatCount = stack[top--];
            
            // Repeat decoded string inside brackets 'repeatCount' times
            for (int j = 0; j < repeatCount; ++j) {
                // Insert characters from temp into decodedString
                for (int k = tempIndex - 1; k >= 0; --k) {
                    decodedString[decodedIndex++] = temp[k];
                }
            }
        } else {
            // Letter encountered, append to decodedString
            decodedString[decodedIndex++] = s[i];
        }
    }
    
    decodedString[decodedIndex] = '\0'; // Null-terminate the decoded string
    return decodedString;
}

int main() {
    char s1[] = "3[a]2[bc]";
    printf("Output for s1: %s\n", decodeString(s1));

    char s2[] = "3[a2[c]]";
    printf("Output for s2: %s\n", decodeString(s2));

    char s3[] = "2[abc]3[cd]ef";
    printf("Output for s3: %s\n", decodeString(s3));

    return 0;
}
