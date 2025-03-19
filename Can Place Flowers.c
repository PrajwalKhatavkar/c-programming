#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            // Check if the previous and next plots are also empty (or out of bounds)
            bool prevEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool nextEmpty = (i == flowerbedSize - 1 || flowerbed[i + 1] == 0);
            
            if (prevEmpty && nextEmpty) {
                flowerbed[i] = 1; // Plant a flower
                count++;
            }
        }
    }
    
    return count >= n;
}

int main() {
    int flowerbed1[] = {1, 0, 0, 0, 1};
    int n1 = 1;
    int size1 = sizeof(flowerbed1) / sizeof(flowerbed1[0]);
    
    int flowerbed2[] = {1, 0, 0, 0, 1};
    int n2 = 2;
    int size2 = sizeof(flowerbed2) / sizeof(flowerbed2[0]);
    
    printf("Example 1: %s\n", canPlaceFlowers(flowerbed1, size1, n1) ? "true" : "false");
    printf("Example 2: %s\n", canPlaceFlowers(flowerbed2, size2, n2) ? "true" : "false");
    
    return 0;
}
