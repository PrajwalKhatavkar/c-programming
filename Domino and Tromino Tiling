#define MOD 1000000007

int numTilings(int n) {
    if (n <= 2) return n;
    
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        dp[i] = (dp[i] + 2 * dp[i - 3]) % MOD;
    }
    
    return dp[n];
}
#include <stdio.h>

int main() {
    int n1 = 3;
    printf("Number of ways to tile a 2 x %d board: %d\n", n1, numTilings(n1));

    int n2 = 1;
    printf("Number of ways to tile a 2 x %d board: %d\n", n2, numTilings(n2));
    
    return 0;
}
