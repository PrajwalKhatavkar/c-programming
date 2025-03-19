#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverseString(char* s, int start, int end) {
    // Reverse the characters in the string from index 'start' to 'end'
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char* reverseWords(char* s) {
    int length = strlen(s);
    int start = 0, end = length - 1;
    
    // Trim leading spaces
    while (start < length && s[start] == ' ') {
        start++;
    }
    
    // Trim trailing spaces
    while (end >= 0 && s[end] == ' ') {
        end--;
    }
    
    // Reverse the entire string
    reverseString(s, start, end);
    
    // Reverse each individual word
    int wordStart = start;
    for (int i = start; i <= end; i++) {
        if (s[i] == ' ') {
            reverseString(s, wordStart, i - 1);
            wordStart = i + 1;
        }
    }
    // Reverse the last word (if any)
    reverseString(s, wordStart, end);
    
    // Remove extra spaces between words
    int i = 0, j = 0;
    while (j <= end) {
        while (j <= end && s[j] == ' ') {
            j++;
        }
        while (j <= end && s[j] != ' ') {
            s[i++] = s[j++];
        }
        if (j <= end) {
            s[i++] = ' ';
        }
    }
    s[i] = '\0';
    
    return s;
}

int main() {
    char s1[] = "the sky is blue";
    printf("Input: \"%s\"\nOutput: \"%s\"\n", s1, reverseWords(s1));

    char s2[] = "  hello world  ";
    printf("Input: \"%s\"\nOutput: \"%s\"\n", s2, reverseWords(s2));
    
    char s3[] = "a good   example";
    printf("Input: \"%s\"\nOutput: \"%s\"\n", s3, reverseWords(s3));
    
    return 0;
}

