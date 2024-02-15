int uniquePaths(int m, int n) {
    int dp[m][n];
    
    // Initialize the first row and first column with 1
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    // Fill the dp table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[m - 1][n - 1];
}
#include <stdio.h>

int main() {
    int m1 = 3, n1 = 7;
    printf("Number of unique paths for m = %d and n = %d: %d\n", m1, n1, uniquePaths(m1, n1));

    int m2 = 3, n2 = 2;
    printf("Number of unique paths for m = %d and n = %d: %d\n", m2, n2, uniquePaths(m2, n2));
    
    return 0;
}
