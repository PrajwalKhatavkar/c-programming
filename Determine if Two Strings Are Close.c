#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool closeStrings(char *word1, char *word2) {
    int count1[26] = {0}; // Array to count frequency of characters in word1
    int count2[26] = {0}; // Array to count frequency of characters in word2
    int present1[26] = {0}; // Array to indicate presence of characters in word1
    int present2[26] = {0}; // Array to indicate presence of characters in word2
    
    // Count frequency of characters in word1 and mark their presence
    for (int i = 0; word1[i] != '\0'; ++i) {
        count1[word1[i] - 'a']++;
        present1[word1[i] - 'a'] = 1;
    }
    
    // Count frequency of characters in word2 and mark their presence
    for (int i = 0; word2[i] != '\0'; ++i) {
        count2[word2[i] - 'a']++;
        present2[word2[i] - 'a'] = 1;
    }
    
    // Sort the counts arrays
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if (count1[i] > count1[j]) {
                int temp = count1[i];
                count1[i] = count1[j];
                count1[j] = temp;
            }
            if (count2[i] > count2[j]) {
                int temp = count2[i];
                count2[i] = count2[j];
                count2[j] = temp;
            }
        }
    }
    
    // Check if both strings have the same set of characters and the same frequency for each character
    for (int i = 0; i < 26; ++i) {
        if ((count1[i] != count2[i]) || (present1[i] != present2[i])) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char word1[] = "abc";
    char word2[] = "bca";
    printf("Output for word1 = \"%s\" and word2 = \"%s\": %s\n", word1, word2, closeStrings(word1, word2) ? "true" : "false");

    char word3[] = "a";
    char word4[] = "aa";
    printf("Output for word3 = \"%s\" and word4 = \"%s\": %s\n", word3, word4, closeStrings(word3, word4) ? "true" : "false");

    char word5[] = "cabbba";
    char word6[] = "abbccc";
    printf("Output for word5 = \"%s\" and word6 = \"%s\": %s\n", word5, word6, closeStrings(word5, word6) ? "true" : "false");

    return 0;
}
