#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countPairs(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int count = 0;

    // Iterate through each row and column
    for (int i = 0; i < n; ++i) {
        // Hash maps to store the counts of each element in the row and column
        int rowMap[201] = {0}; // 200 is the maximum value in the grid
        int colMap[201] = {0};
        
        // Count occurrences of each element in the row and column
        for (int j = 0; j < n; ++j) {
            rowMap[grid[i][j]]++;
            colMap[grid[j][i]]++;
        }
        
        // Check if the row and column are equal
        for (int j = 0; j < n; ++j) {
            if (rowMap[grid[i][j]] != colMap[grid[i][j]]) {
                break; // If counts are not equal, move to the next row
            }
            if (j == n - 1) {
                count++; // If all counts are equal, increment the count of pairs
            }
        }
    }

    return count;
}

int main() {
    int grid1[3][3] = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    int* gridColSize1 = (int*)malloc(3 * sizeof(int));
    gridColSize1[0] = gridColSize1[1] = gridColSize1[2] = 3;
    printf("Output for grid1: %d\n", countPairs((int**)grid1, 3, gridColSize1));

    int grid2[4][4] = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    int* gridColSize2 = (int*)malloc(4 * sizeof(int));
    gridColSize2[0] = gridColSize2[1] = gridColSize2[2] = gridColSize2[3] = 4;
    printf("Output for grid2: %d\n", countPairs((int**)grid2, 4, gridColSize2));

    return 0;
}
