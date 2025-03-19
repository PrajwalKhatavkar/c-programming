#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int left = 0, right = heightSize - 1;
    
    while (left < right) {
        int currentArea = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxArea;
}

int main() {
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize1 = sizeof(height1) / sizeof(height1[0]);
    printf("Example 1: %d\n", maxArea(height1, heightSize1));

    int height2[] = {1, 1};
    int heightSize2 = sizeof(height2) / sizeof(height2[0]);
    printf("Example 2: %d\n", maxArea(height2, heightSize2));
    
    return 0;
}
