#include <stdio.h>
#include <string.h>

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // If the lengths of the strings are different, there can't be a common divisor
    if (len1 != len2) {
        return "";
    }
    
    // Check if the two strings are equal
    if (strcmp(str1, str2) == 0) {
        return str1;
    }
    
    // Find the longest common prefix
    int i = 0;
    while (i < len1 && str1[i] == str2[i]) {
        i++;
    }
    
    // Extract the longest common prefix
    char* gcd = (char*)malloc((i + 1) * sizeof(char));
    strncpy(gcd, str1, i);
    gcd[i] = '\0';
    
    return gcd;
}

int main() {
    char str1[] = "ABCABC";
    char str2[] = "ABC";
    
    char* gcd = gcdOfStrings(str1, str2);
    
    printf("GCD of \"%s\" and \"%s\" is \"%s\"\n", str1, str2, gcd);
    
    // Free the dynamically allocated memory
    free(gcd);
    
    return 0;
}
