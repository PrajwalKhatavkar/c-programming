#include <stdbool.h>
#include <stdlib.h>

void dfs(int** isConnected, int n, int* visited, int city) {
    visited[city] = 1;
    for (int i = 0; i < n; ++i) {
        if (isConnected[city][i] && !visited[i]) {
            dfs(isConnected, n, visited, i);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    int provinces = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(isConnected, n, visited, i);
            provinces++;
        }
    }
    free(visited);
    return provinces;
}

int main() {
    int isConnectedSize1 = 3;
    int isConnectedColSize1[] = {3, 3, 3};
    int* isConnected1[] = {
        (int[]){1, 1, 0},
        (int[]){1, 1, 0},
        (int[]){0, 0, 1}
    };
    printf("Example 1 output: %d\n", findCircleNum(isConnected1, isConnectedSize1, isConnectedColSize1));
    
    int isConnectedSize2 = 3;
    int isConnectedColSize2[] = {3, 3, 3};
    int* isConnected2[] = {
        (int[]){1, 0, 0},
        (int[]){0, 1, 0},
        (int[]){0, 0, 1}
    };
    printf("Example 2 output: %d\n", findCircleNum(isConnected2, isConnectedSize2, isConnectedColSize2));
    
    return 0;
}
