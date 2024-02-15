int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize];
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for (int i = 2; i < costSize; i++) {
        dp[i] = cost[i] + fmin(dp[i - 1], dp[i - 2]);
    }
    
    return fmin(dp[costSize - 1], dp[costSize - 2]);
}
#include <stdio.h>

int main() {
    int cost1[] = {10, 15, 20};
    int costSize1 = sizeof(cost1) / sizeof(cost1[0]);
    printf("Minimum cost: %d\n", minCostClimbingStairs(cost1, costSize1));

    int cost2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int costSize2 = sizeof(cost2) / sizeof(cost2[0]);
    printf("Minimum cost: %d\n", minCostClimbingStairs(cost2, costSize2));
    
    return 0;
}
