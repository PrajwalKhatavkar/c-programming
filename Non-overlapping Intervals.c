#include <stdlib.h>
#include <stdio.h>

// Comparator function for sorting intervals based on their end points
int compareIntervals(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    return interval1[1] - interval2[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    // Sort intervals based on their end points
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);

    // Initialize variables
    int count = 1;
    int end = intervals[0][1];

    // Iterate through the sorted intervals and count the number of removals needed
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= end) {
            // No overlap, update end point
            end = intervals[i][1];
            count++;
        }
    }

    // The number of removals needed is the difference between the total intervals and the non-overlapping intervals
    return intervalsSize - count;
}

int main() {
    // Example usage
    int intervalsSize = 4;
    int intervalsColSize = 2;
    int* intervals[] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = eraseOverlapIntervals(intervals, intervalsSize, &intervalsColSize);
    printf("Minimum number of intervals to remove: %d\n", result);

    return 0;
}
