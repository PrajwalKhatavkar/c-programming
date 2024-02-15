#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize, int fee) {
    int hold = -prices[0]; // Maximum profit if we hold a stock on the first day
    int cash = 0; // Maximum profit if we don't hold a stock on the first day
    
    for (int i = 1; i < pricesSize; i++) {
        int prevHold = hold;
        int prevCash = cash;
        
        hold = max(prevHold, prevCash - prices[i]);
        cash = max(prevCash, prevHold + prices[i] - fee);
    }
    
    return cash;
}

int main() {
    int prices1[] = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Maximum profit: %d\n", maxProfit(prices1, size1, fee1));

    int prices2[] = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Maximum profit: %d\n", maxProfit(prices2, size2, fee2));

    return 0;
}
