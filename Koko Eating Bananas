#include <stdio.h>
#include <stdbool.h>

bool canEatAll(int* piles, int pilesSize, int k, int h) {
    int hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    // Find the maximum number of bananas in any pile
    int maxPile = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }
    
    // Perform binary search to find the minimum eating speed
    int left = 1, right = maxPile;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, pilesSize, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int piles1[] = {3, 6, 7, 11};
    int h1 = 8;
    printf("%d\n", minEatingSpeed(piles1, 4, h1)); // Output: 4
    
    int piles2[] = {30, 11, 23, 4, 20};
    int h2 = 5;
    printf("%d\n", minEatingSpeed(piles2, 5, h2)); // Output: 30
    
    int h3 = 6;
    printf("%d\n", minEatingSpeed(piles2, 5, h3)); // Output: 23
    
    return 0;
}
