#include <stdio.h>
#include <string.h>

int maxVowels(char *s, int k) {
    int max_vowels = 0;
    int vowels_count = 0;
    int len = strlen(s);

    // Count vowels in the first window of length k
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels_count++;
        }
    }
    max_vowels = vowels_count;

    // Slide the window and update max_vowels
    for (int i = k; i < len; ++i) {
        if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
            vowels_count--;
        }
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels_count++;
        }
        max_vowels = (vowels_count > max_vowels) ? vowels_count : max_vowels;
    }

    return max_vowels;
}

int main() {
    char s1[] = "abciiidef";
    int k1 = 3;
    printf("Output for s1: %d\n", maxVowels(s1, k1));

    char s2[] = "aeiou";
    int k2 = 2;
    printf("Output for s2: %d\n", maxVowels(s2, k2));

    char s3[] = "leetcode";
    int k3 = 3;
    printf("Output for s3: %d\n", maxVowels(s3, k3));

    return 0;
}
