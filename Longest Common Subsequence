#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char * text1, char * text2) {
    int m = strlen(text1);
    int n = strlen(text2);
    int dp[m+1][n+1];

    // Initialize the first row and first column with 0
    memset(dp, 0, sizeof(dp));
    
    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    char text1[] = "abcde";
    char text2[] = "ace";
    printf("Longest common subsequence length: %d\n", longestCommonSubsequence(text1, text2));

    char text3[] = "abc";
    char text4[] = "abc";
    printf("Longest common subsequence length: %d\n", longestCommonSubsequence(text3, text4));

    char text5[] = "abc";
    char text6[] = "def";
    printf("Longest common subsequence length: %d\n", longestCommonSubsequence(text5, text6));

    return 0;
}
