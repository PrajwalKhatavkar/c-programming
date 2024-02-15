#include <stdlib.h>
#include <stdio.h>

// Comparator function for sorting intervals based on their end points
int compareIntervals(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    return interval1[1] - interval2[1];
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) return 0;

    // Sort intervals based on their end points
    qsort(points, pointsSize, sizeof(int*), compareIntervals);

    // Initialize variables
    int arrows = 1;
    int end = points[0][1];

    // Iterate through the sorted intervals and count the number of arrows needed
    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > end) {
            // Current interval doesn't overlap with the previous one, use a new arrow
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}

int main() {
    // Example usage
    int pointsSize = 4;
    int pointsColSize = 2;
    int* points[] = {{10,16},{2,8},{1,6},{7,12}};
    int result = findMinArrowShots(points, pointsSize, &pointsColSize);
    printf("Minimum number of arrows: %d\n", result);

    return 0;
}
