#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a cell in the maze
typedef struct {
    int row;
    int col;
} Cell;

// Function to check if a cell is valid within the maze boundaries
bool isValid(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

// Function to find the nearest exit from the entrance in the maze
int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance, int entranceSize) {
    int m = mazeSize, n = *mazeColSize;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    // Initialize visited array and queue for BFS
    bool visited[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }

    visited[entrance[0]][entrance[1]] = true; // Mark entrance cell as visited
    int steps = 0;

    // Initialize queue for BFS
    Cell queue[m * n];
    int front = 0, rear = 0;
    queue[rear++] = (Cell){entrance[0], entrance[1]};

    // Perform BFS
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; ++i) {
            Cell current = queue[front++];
            int row = current.row, col = current.col;

            // Check if current cell is an exit
            if ((row == 0 || row == m - 1 || col == 0 || col == n - 1) && !(row == entrance[0] && col == entrance[1])) {
                return steps;
            }

            // Explore neighbors
            for (int d = 0; d < 4; ++d) {
                int newRow = row + dirs[d][0];
                int newCol = col + dirs[d][1];
                if (isValid(newRow, newCol, m, n) && maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    queue[rear++] = (Cell){newRow, newCol};
                }
            }
        }
        steps++;
    }
    return -1; // No exit found
}

// Sample test cases
int main() {
    char *maze1[] = {"+.+","...","+++"};
    int entrance1[] = {1, 0};
    int mazeSize1 = 3, mazeColSize1 = 3, entranceSize1 = 2;
    printf("Output for Test Case 1: %d\n", nearestExit(maze1, mazeSize1, &mazeColSize1, entrance1, entranceSize1));

    char *maze2[] = {"+.+","...","+++"};
    int entrance2[] = {1, 2};
    int mazeSize2 = 3, mazeColSize2 = 3, entranceSize2 = 2;
    printf("Output for Test Case 2: %d\n", nearestExit(maze2, mazeSize2, &mazeColSize2, entrance2, entranceSize2));

    char *maze3[] = {"++"};
    int entrance3[] = {0, 0};
    int mazeSize3 = 1, mazeColSize3 = 2, entranceSize3 = 2;
    printf("Output for Test Case 3: %d\n", nearestExit(maze3, mazeSize3, &mazeColSize3, entrance3, entranceSize3));

    return 0;
}
