#include <stdio.h>
#include <string.h>

char* mergeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    // Allocate memory for the merged string
    char* merged = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    
    int i = 0, j = 0, k = 0;
    
    // Merge the strings by adding letters in alternating order
    while (i < len1 && j < len2) {
        merged[k++] = word1[i++];
        merged[k++] = word2[j++];
    }
    
    // If word1 is longer, append the remaining letters from word1
    while (i < len1) {
        merged[k++] = word1[i++];
    }
    
    // If word2 is longer, append the remaining letters from word2
    while (j < len2) {
        merged[k++] = word2[j++];
    }
    
    // Add null terminator to the end of the merged string
    merged[k] = '\0';
    
    return merged;
}

int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    
    char* merged = mergeStrings(word1, word2);
    
    printf("Merged string: %s\n", merged);
    
    // Free the dynamically allocated memory
    free(merged);
    
    return 0;
}
