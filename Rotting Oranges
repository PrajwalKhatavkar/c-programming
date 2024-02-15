#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a cell in the grid
typedef struct {
    int row;
    int col;
} Cell;

// Function to check if a cell is valid within the grid boundaries
bool isValid(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

// Function to calculate the minimum number of minutes required to rot all oranges
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    // Initialize queue for BFS
    Cell queue[m * n];
    int front = 0, rear = 0;

    // Add all rotten oranges to the queue
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Cell){i, j};
            }
        }
    }

    int minutes = 0;
    // Perform BFS
    while (front < rear) {
        int size = rear - front;
        bool freshOranges = false;
        for (int i = 0; i < size; ++i) {
            Cell current = queue[front++];
            int row = current.row, col = current.col;

            // Check adjacent cells and update fresh oranges to rotten
            for (int d = 0; d < 4; ++d) {
                int newRow = row + dirs[d][0];
                int newCol = col + dirs[d][1];
                if (isValid(newRow, newCol, m, n) && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    queue[rear++] = (Cell){newRow, newCol};
                    freshOranges = true;
                }
            }
        }
        if (freshOranges) {
            minutes++;
        }
    }

    // Check if there are any fresh oranges left
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                return -1; // Some fresh oranges are unreachable
            }
        }
    }

    return minutes;
}

// Sample test cases
int main() {
    int grid1[][3] = {{2,1,1},{1,1,0},{0,1,1}};
    int* gridColSize1 = (int*)malloc(sizeof(int));
    *gridColSize1 = 3;
    printf("Output for Test Case 1: %d\n", orangesRotting((int**)grid1, 3, gridColSize1));

    int grid2[][3] = {{2,1,1},{0,1,1},{1,0,1}};
    int* gridColSize2 = (int*)malloc(sizeof(int));
    *gridColSize2 = 3;
    printf("Output for Test Case 2: %d\n", orangesRotting((int**)grid2, 3, gridColSize2));

    int grid3[][1] = {{0,2}};
    int* gridColSize3 = (int*)malloc(sizeof(int));
    *gridColSize3 = 1;
    printf("Output for Test Case 3: %d\n", orangesRotting((int**)grid3, 1, gridColSize3));

    return 0;
}
