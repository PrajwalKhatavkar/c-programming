#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    while (*s != '\0' && *t != '\0') {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    return *s == '\0';
}

int main() {
    char s1[] = "abc";
    char t1[] = "ahbgdc";
    printf("Example 1: %s\n", isSubsequence(s1, t1) ? "true" : "false");

    char s2[] = "axc";
    char t2[] = "ahbgdc";
    printf("Example 2: %s\n", isSubsequence(s2, t2) ? "true" : "false");
    
    return 0;
}
