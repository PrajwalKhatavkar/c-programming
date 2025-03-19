#include <stdio.h>
#include <stdbool.h>

int compress(char* chars, int charsSize) {
    int index = 0; // Pointer to write compressed characters
    int i = 0;     // Pointer to iterate through the original array
    
    while (i < charsSize) {
        char currentChar = chars[i];
        int count = 0;
        
        // Count consecutive occurrences of current character
        while (i < charsSize && chars[i] == currentChar) {
            count++;
            i++;
        }
        
        // Write compressed character
        chars[index++] = currentChar;
        
        // If count is greater than 1, write compressed count
        if (count > 1) {
            char countStr[5]; // Maximum digits for count is 4
            int countLength = snprintf(countStr, 5, "%d", count);
            for (int j = 0; j < countLength; j++) {
                chars[index++] = countStr[j];
            }
        }
    }
    
    return index;
}

int main() {
    char chars1[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int charsSize1 = 7;
    int len1 = compress(chars1, charsSize1);
    printf("Example 1: Length = %d, Compressed string = [", len1);
    for (int i = 0; i < len1; i++) {
        printf("%c%c", chars1[i], (i == len1 - 1) ? ']' : ',');
    }
    printf("\n");

    char chars2[] = {'a'};
    int charsSize2 = 1;
    int len2 = compress(chars2, charsSize2);
    printf("Example 2: Length = %d, Compressed string = [", len2);
    for (int i = 0; i < len2; i++) {
        printf("%c%c", chars2[i], (i == len2 - 1) ? ']' : ',');
    }
    printf("\n");
    
    char chars3[] = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int charsSize3 = 13;
    int len3 = compress(chars3, charsSize3);
    printf("Example 3: Length = %d, Compressed string = [", len3);
    for (int i = 0; i < len3; i++) {
        printf("%c%c", chars3[i], (i == len3 - 1) ? ']' : ',');
    }
    printf("\n");
    
    return 0;
}
