#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isVowel(char c) {
    // Check if the character is a vowel (case-insensitive)
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char* reverseVowels(char* s) {
    // Initialize two pointers, one at the beginning and one at the end of the string
    int start = 0;
    int end = strlen(s) - 1;
    
    while (start < end) {
        // Find the next vowel from the start of the string
        while (start < end && !isVowel(s[start])) {
            start++;
        }
        // Find the next vowel from the end of the string
        while (start < end && !isVowel(s[end])) {
            end--;
        }
        // Swap the vowels
        if (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
    
    return s;
}

int main() {
    char s1[] = "hello";
    printf("Input: %s\nOutput: %s\n", s1, reverseVowels(s1));

    char s2[] = "leetcode";
    printf("Input: %s\nOutput: %s\n", s2, reverseVowels(s2));
    
    return 0;
}
